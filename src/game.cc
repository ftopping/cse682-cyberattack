#include <iostream>

#include "game.hh"

#include "levels/menu.hh"
#include "levels/1.hh"

Game::Game() {
	levels.push_back(new LevelMenu(this));
	levels.push_back(new Level1());
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
		bool won = level->main();

		if (won) {
			std::cout << "WON" << std::endl;
		}
		else {
			std::cout << "LOST" << std::endl;
		}
	}
	while (this->startLevel || startLevel);
}
