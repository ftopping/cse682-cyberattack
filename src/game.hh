#pragma once

#include "vector"

#include "level.hh"

class Game {
	public:
		int startLevel = 0;
		int finishedLevel = 0;

		Game();
		~Game();
		void main();

	protected:
		std::vector<Level *> levels;
};
