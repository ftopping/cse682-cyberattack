#include <iostream>
#include "game.hh"

#include "levels/menu.hh"

Game::Game() {
	levels.push_back(new LevelMenu(this));
}

Game::~Game() {
	for (Level * level : this->levels) {
		delete level;
	}
	this->levels.clear();
}

void Game::main() {
	int startLevel = this->startLevel;
	this->startLevel = 0;

	Level * level = this->levels[startLevel];
	level->main();
}
