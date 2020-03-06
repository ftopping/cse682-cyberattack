#include <iostream>
#include "game.hh"

#include "levels/menu.hh"

Game::Game() {
	LevelMenu menu(this);
	levels.push_back(menu);
}

void Game::main() {
	int startLevel = this->startLevel;
	this->startLevel = 0;

	Level level = this->levels[startLevel];
	level.main();
}
