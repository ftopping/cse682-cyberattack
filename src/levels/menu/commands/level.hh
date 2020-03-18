#pragma once

#include "../../../command.hh"
#include "../../menu.hh"

class LevelMenuCommandLevel: public Command {
	public:
		/**
		 * Constructor.
		 *
		 * @param menu Menu instance.
		 * @param level Level number.
		 */
		LevelMenuCommandLevel(LevelMenu * menu, int level);

		/**
		 * Destructor.
		 */
		virtual ~LevelMenuCommandLevel();

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
		 * Menu instance.
		 */
		LevelMenu * menu;

		/**
		 * Level number.
		 */
		int level;
};
