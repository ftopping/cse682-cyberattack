#pragma once

#include "../../../command.hh"

class Level1CommandLearn: public Command {
	public:
		/**
		 * Constructor.
		 */
		Level1CommandLearn();

		/**
		 * Destructor.
		 */
		virtual ~Level1CommandLearn();

		/**
		 * The main entry point.
		 *
		 * @param argc Argument count.
		 * @param argv Argument values.
		 * @returns Exit code.
		 */
		virtual int main(int argc, char ** argv);
};
