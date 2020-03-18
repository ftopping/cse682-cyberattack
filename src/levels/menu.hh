#pragma once

#include "../level.hh"
#include "../game.hh"

class LevelMenu: public Level {
	public:
		int startLevel = 0;

		LevelMenu(Game *, int levels);
		std::string welcome();
		int finishedLevel();
		void setStartLevel(int level);

	protected:
		Game * game;
		int levels;
};
