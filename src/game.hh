#pragma once

#include "vector"

#include "level.hh"

class Game {
	public:
		/**
		 * Flag to start a level instead of menu.
		 */
		int startLevel = 0;

		/**
		 * Current level of completion.
		 */
		int finishedLevel = 0;

		/**
		 * Constructor.
		 */
		Game();

		/**
		 * Destructor.
		 */
		~Game();

		/**
		 * Main loop.
		 */
		void main();

	protected:
		/**
		 * Level instances.
		 */
		std::vector<Level *> levels;
};
