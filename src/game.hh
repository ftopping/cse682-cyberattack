#pragma once

#include "vector"

#include "level.hh"

class Game {
	public:
		int startLevel = 0;

		Game();
		~Game();
		void main();

	private:
		std::vector<Level *> levels;
};
