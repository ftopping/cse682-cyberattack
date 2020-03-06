#pragma once

#include "../level.hh"
#include "../game.hh"

class LevelMenu: public Level {
	public:
		LevelMenu(Game *);

	private:
		Game * game;
};
