#include <iostream>
#include <replxx.hxx>

#include "shell.hh"

using Replxx = replxx::Replxx;

Shell::Shell(std::string host, std::string welcome) {
	this->host = host;
	this->welcome = welcome;
}

void Shell::main() {
	// Print welcome message if one set.
	if (this->welcome.length()) {
		std::cout << this->welcome << std::endl;
	}

	Replxx rx;
	rx.install_window_change_handler();
	rx.set_max_history_size(128);
	rx.set_max_hint_rows(3);

	std::string prompt = "\x1b[1;32mhacker@" + this->host + "\x1b[0m$ ";
	for (;;) {
		char const * cinput = nullptr;
		do {
			cinput = rx.input(prompt);
		}
		while ((cinput == nullptr) && (errno == EAGAIN));
		if (cinput == nullptr) {
			break;
		}
		std::string input = cinput;

		// Parse arguments.
		std::vector<std::string> args;
		try {
			args = this->parseArgs(input);
		}
		catch (const std::invalid_argument & ex) {
			rx.history_add(input);
			std::cout << "Shell Error: " << ex.what() << std::endl;
			continue;
		}

		// If no arguments after parsing, ignore.
		if (!args.size()) {
			continue;
		}
		rx.history_add(input);

		// Run command if possible.
		if (!this->runCommand(args)) {
			std::cout <<
				"Shell Error: Command not found: \"" <<
				args[0] <<
				"\"" <<
				std::endl;
		}
	}
}

bool Shell::runCommand(const std::vector<std::string> & args) {
	auto argsArgv = this->argsArgvView(args);
	int argc = argsArgv.size();
	char ** argv = argsArgv.data();

	// TODO: Use to run command.
	std::cout << "[" << argc << "]:\n";
	for (int i = 0; i < argc; i++) {
		std::cout << "  [" << i << "]: " << argv[i] << "\n";
	}

	return false;
}

std::string Shell::shellUnquote(std::string quotedString) {
	// Function based on glib gshell g_shell_unquote.
	std::string result = "";
	size_t end = 0;
	size_t start = 0;
	size_t l = quotedString.length();

	while (start < l) {
		while (
			start < l &&
			!(
				quotedString[start] == '"' ||
				quotedString[start] == '\''
			)
		) {
			if (quotedString[start] == '\\') {
				start++;

				if (start < l) {
					if (quotedString[start] != '\n') {
						result += quotedString[start];
					}
					start++;
				}
			}
			else {
				result += quotedString[start];
				start++;
			}
		}

		if (start < l) {
			std::string dest = "";
			int breakout = 0;
			do {
				size_t s = start;
				char quoteChar = quotedString[s];
				if (quoteChar != '"' && quoteChar != '\'') {
					throw std::invalid_argument("Bad Quoting");
				}
				s++;

				if (quoteChar == '"') {
					while (s < l) {
						if (quotedString[s] == '"') {
							s++;
							end = s;

							breakout = 1;
							break;
						}
						else if (quotedString[s] == '\\') {
							s++;
							if (
								quotedString[s] == '"' ||
								quotedString[s] == '\\' ||
								quotedString[s] == '`' ||
								quotedString[s] == '$' ||
								quotedString[s] == '\n'
							) {
								dest += quotedString[s];
								s++;
							}
							else {
								dest += '\\';
							}
						}
						else {
							dest += quotedString[s];
							s++;
						}
					}
					if (breakout) {
						break;
					}
				}
				else {
					while (s < l) {
						if (quotedString[s] == '\'') {
							s++;
							end = s;

							breakout = 1;
							break;
						}
						else {
							dest += quotedString[s];
							s++;
						}
					}
					if (breakout) {
						break;
					}
				}
			}
			while (0);

			if (breakout) {
				result += dest;
				start = end;
			}
			else {
				throw std::invalid_argument("Bad Quoting");
			}
		}
	}

	return result;
}

std::vector<std::string> Shell::tokenizeCommandLine(std::string commandLine) {
	// Function based on glib gshell tokenize_command_line.
	std::vector<std::string> result;
	char currentQuote = '\0';
	std::string currentToken = "";
	std::string * currentTokenP = nullptr;
	bool quoted = false;

	size_t l = commandLine.length();
	size_t i = 0;
	while (i < l) {
		char p = commandLine[i];

		if (currentQuote == '\\') {
			if (p != '\n') {
				if (!currentTokenP) {
					currentToken = "";
					currentTokenP = &currentToken;
				}
				*currentTokenP += '\\';
				*currentTokenP += p;
			}
			currentQuote = '\0';
		}
		else if (currentQuote == '#') {
			while (i < l && commandLine[i] != '\n') {
				i++;
			}

			if (i < l) {
				p = commandLine[i];
			}
			currentQuote = '\0';

			if (i >= l) {
				break;
			}
		}
		else if (currentQuote) {
			if (
				p == currentQuote &&
				!(currentQuote == '"' && quoted)
			) {
				currentQuote = '\0';
			}
			if (!currentTokenP) {
				currentToken = "";
				currentTokenP = &currentToken;
			}
			*currentTokenP += p;
		}
		else {
			if (p == '\n' || p == ' ' || p == '\t') {
				if (currentTokenP) {
					result.push_back(*currentTokenP);
					currentTokenP = nullptr;
				}
			}
			else if (p == '\'' || p == '"' || p == '\\') {
				if (p != '\\') {
					if (!currentTokenP) {
						currentToken = "";
						currentTokenP = &currentToken;
					}
					*currentTokenP += p;
				}
				currentQuote = p;
			}
			else if (p == '#') {
				if (!i) {
					currentQuote = p;
				}
				else {
					if (
						commandLine[i - 1] == ' ' ||
						commandLine[i - 1] == '\n' ||
						commandLine[i - 1] == '\0'
					) {
						currentQuote = p;
					}
					else {
						if (!currentTokenP) {
							currentToken = "";
							currentTokenP = &currentToken;
						}
						*currentTokenP += p;
					}
				}
			}
			else {
				if (!currentTokenP) {
					currentToken = "";
					currentTokenP = &currentToken;
				}
				*currentTokenP += p;
			}
		}

		if (p != '\\') {
			quoted = false;
		}
		else {
			quoted = !quoted;
		}

		i++;
	}

	if (currentTokenP) {
		result.push_back(*currentTokenP);
		currentTokenP = nullptr;
	}

	if (currentQuote != '\0') {
		throw std::invalid_argument("Bad Quoting");
	}

	return result;
}

std::vector<std::string> Shell::parseArgs(std::string commandLine) {
	// Function based on glib gshell g_shell_parse_argv.
	std::vector<std::string> args = this->tokenizeCommandLine(commandLine);
	for (size_t i = 0, l = args.size(); i < l; i++) {
		args[i] = this->shellUnquote(args[i]);
	}
	return args;
}

std::vector<char *> Shell::argsArgvView(const std::vector<std::string> & args) {
	std::vector<char *> argc;
	for (size_t i = 0, l = args.size(); i < l; i++) {
		argc.push_back((char *)args.at(i).c_str());
	}
	return argc;
}
