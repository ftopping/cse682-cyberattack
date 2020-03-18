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

	// Check that this level is unlocked.
	int nextLevel = this->menu->finishedLevel() + 1;
	if (this->level > nextLevel) {
		std::cout <<
			"ERROR: Finish level " << nextLevel << " first." <<
			std::endl;
		return 0;
	}

	this->menu->setStartLevel(this->level);
	return 0;
}
