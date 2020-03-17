#include "menu.hh"

#include "menu/commands/level.hh"

LevelMenu::LevelMenu(Game * game, int levels) {
	this->game = game;
	this->name = "menu";
	this->welcome = "TODO: Welcome message.";

	for (int i = 1; i <= levels; i++) {
		this->commands.push_back(new LevelMenuCommandLevel(this, i));
	}
}

void LevelMenu::setStartLevel(int level) {
	this->game->startLevel = level;
	this->shell->exit = true;
}
