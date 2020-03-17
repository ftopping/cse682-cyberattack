#pragma once

#include "../level.hh"
#include "../game.hh"

class LevelMenu: public Level {
	public:
		int startLevel = 0;

		LevelMenu(Game *);
		void setStartLevel(int level);

	protected:
		Game * game;
};
