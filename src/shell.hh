#pragma once

#include <string>

class Shell {
	public:
		std::string host;
		std::string welcome;

		Shell(std::string host, std::string welcome);
		void main();

		bool runCommand(const std::vector<std::string> & args);

		/**
		 * Unquote a shell argument.
		 *
		 * @param quotedString Quoted string.
		 * @returns Unquoted string.
		 */
		std::string shellUnquote(std::string quotedString);

		/**
		 * Tokenize a command line string into vector.
		 *
		 * @param commandLine Command line string.
		 */
		std::vector<std::string> tokenizeCommandLine(std::string commandLine);

		/**
		 * Parse a command line string into vector.
		 *
		 * @param commandLine Command line string.
		 */
		std::vector<std::string> parseArgs(std::string commandLine);

		/**
		 * Get argv vector view of args.
		 *
		 * @param args Arguments vector
		 * @returns Pointer vector.
		 */
		std::vector<char *> argsArgvView(const std::vector<std::string> & args);
};
