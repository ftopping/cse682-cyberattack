#include "level.hh"

#include <iostream>

LevelMenuCommandLevel::LevelMenuCommandLevel(LevelMenu * menu, int level) {
	this->name = "level" + std::to_string(level);
	this->menu = menu;
	this->level = level;
}

LevelMenuCommandLevel::~LevelMenuCommandLevel() {
}

int LevelMenuCommandLevel::main(int argc, char ** argv) {
	(void)argc;
	(void)argv;

	std::cout << "Starting level: " << this->level << std::endl;

	this->menu->setStartLevel(this->level);

	return 0;
}
