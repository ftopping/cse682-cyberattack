#pragma once

#include "../../../command.hh"
#include "../../1.hh"

class Level1CommandChallenge: public Command {
	public:
		/**
		 * Constructor.
		 *
		 * @param level Level instance.
		 */
		Level1CommandChallenge(Level1 * level);

		/**
		 * Destructor.
		 */
		virtual ~Level1CommandChallenge();

		/**
		 * The main entry point.
		 *
		 * @param argc Argument count.
		 * @param argv Argument values.
		 * @returns Exit code.
		 */
		virtual int main(int argc, char ** argv);

	protected:
		/**
		 * Level instance.
		 */
		Level1 * level;
};
