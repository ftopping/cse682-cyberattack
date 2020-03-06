#include <iostream>
#include <replxx.hxx>

#include "shell.hh"

using Replxx = replxx::Replxx;

Shell::Shell(std::string host, std::string welcome) {
	this->host = host;
	this->welcome = welcome;
}

void Shell::main() {
	std::cout << this->welcome << std::endl;

	Replxx rx;
	rx.install_window_change_handler();
	rx.set_max_history_size(128);
	rx.set_max_hint_rows(3);

	std::string prompt = "\x1b[1;32mhacker@" + this->host + "\x1b[0m$ ";
	for (;;) {
		char const * cinput{ nullptr };
		do {
			cinput = rx.input(prompt);
		}
		while ((cinput == nullptr) && (errno == EAGAIN));
		if (cinput == nullptr) {
			break;
		}

		std::string input {cinput};
		if (input.empty()) {
			continue;
		}
		rx.history_add(input);

		// TODO: Parse into argc/argv.
		std::cout << input << std::endl;
	}
}
