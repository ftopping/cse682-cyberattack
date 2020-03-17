#include <iostream>

#include "game.hh"

#include "levels/menu.hh"
#include "levels/1.hh"

Game::Game() {
	std::vector<Level *> levels;
	levels.push_back(new Level1());

	this->levels.push_back(new LevelMenu(this, levels.size()));
	for (auto level : levels) {
		this->levels.push_back(level);
	}
	levels.clear();
}

Game::~Game() {
	for (auto level : this->levels) {
		delete level;
	}
	this->levels.clear();
}

void Game::main() {
	for (int startLevel = -1; this->startLevel || startLevel;) {
		startLevel = this->startLevel;
		this->startLevel = 0;

		Level * level = this->levels.at(startLevel);
		bool won = level->main();

		if (won) {
			std::cout << "WON" << std::endl;
		}
		else {
			std::cout << "LOST" << std::endl;
		}
		std::cout << startLevel << std::endl;
	}
}
