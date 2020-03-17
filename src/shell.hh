#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

#include "command.hh"

class Shell {
	public:
		bool exit = false;

		Shell(std::string host, std::string welcome);
		~Shell();
		void addCommand(Command * command);
		void main();

	protected:
		std::string host;
		std::string welcome;
		std::unordered_map<std::string, Command *> commandMap;

		void help();

		Command * getCommand(std::string name);

		int runCommand(
			Command * command,
			const std::vector<std::string> & args
		);

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
