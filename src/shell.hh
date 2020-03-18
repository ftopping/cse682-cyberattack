#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

#include "command.hh"

class Shell {
	public:
		/**
		 * Flage for the shell to exit.
		 */
		bool exit = false;

		/**
		 * Constructor.
		 *
		 * @param host Shell prompt host.
		 * @param welcome Shell welcome text.
		 */
		Shell(std::string host, std::string welcome);

		/**
		 * Destructor.
		 */
		~Shell();

		/**
		 * Register command with shell.
		 *
		 * @param command Command instance.
		 */
		void addCommand(Command * command);

		/**
		 * Main loop.
		 */
		void main();

	protected:
		/**
		 * Shell prompt host.
		 */
		std::string host;

		/**
		 * Shell welcome text.
		 */
		std::string welcome;

		/**
		 * Shell command name map.
		 */
		std::unordered_map<std::string, Command *> commandMap;

		/**
		 * Output the help text.
		 */
		void help();

		/**
		 * Get command by name if exists.
		 *
		 * @param name Command name.
		 * @returns Command or null pointer.
		 */
		Command * getCommand(std::string name);

		/**
		 * Runn command with arguments.
		 *
		 * @param command Command instance.
		 * @param args Shell arguments.
		 * @returns Exit code.
		 */
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
