#pragma once

#include "../level.hh"
#include "../game.hh"

class LevelMenu: public Level {
	public:
		/**
		 * A variable for level commands to set to start level.
		 */
		int startLevel = 0;

		/**
		 * Constructor.
		 *
		 * @param game Game instance.
		 * @param levels Level count.
		 */
		LevelMenu(Game * game, int levels);

		/**
		 * Get welcome text for the shell.
		 *
		 * @returns Welcome text.
		 */
		virtual std::string welcome();

		/**
		 * Get currently finished level.
		 *
		 * @returns Finished level.
		 */
		int finishedLevel();

		/**
		 * Set start level flag.
		 *
		 * @param level Level number.
		 */
		void setStartLevel(int level);

	protected:
		/**
		 * Game instance.
		 */
		Game * game;

		/**
		 * Level count.
		 */
		int levels;
};
