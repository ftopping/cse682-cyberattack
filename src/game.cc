#include "game.hh"

#include "levels/menu.hh"

Game::Game() {
	levels.push_back(new LevelMenu(this));
}

Game::~Game() {
	for (auto level : this->levels) {
		delete level;
	}
	this->levels.clear();
}

void Game::main() {
	do {
		int startLevel = this->startLevel;
		this->startLevel = 0;

		Level * level = this->levels.at(startLevel);
		level->main();
	}
	while (this->startLevel);
}
