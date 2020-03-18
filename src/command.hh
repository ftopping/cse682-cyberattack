#pragma once

#include <string>
#include <stdexcept>

class Command {
	public:
		/**
		 * Command name for shell.
		 */
		std::string name;

		/**
		 * Constructor.
		 */
		Command();

		/**
		 * Destructor.
		 */
		virtual ~Command();

		/**
		 * Initialization method.
		 */
		virtual void start();

		/**
		 * The main entry point.
		 *
		 * @param argc Argument count.
		 * @param argv Argument values.
		 * @returns Exit code.
		 */
		virtual int main(int argc, char ** argv);
};
