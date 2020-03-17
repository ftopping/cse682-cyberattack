#pragma once

#include "../level.hh"
#include "../game.hh"

class LevelMenu: public Level {
	public:
		int startLevel = 0;

		LevelMenu(Game *, int levels);
		int finishedLevel();
		void setStartLevel(int level);

	protected:
		Game * game;
};
