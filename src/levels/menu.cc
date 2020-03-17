#include "menu.hh"

#include "menu/commands/level.hh"

LevelMenu::LevelMenu(Game * game) {
	this->game = game;
	this->name = "menu";
	this->welcome = "TODO: Welcome message.";
	this->commands.push_back(new LevelMenuCommandLevel(this, 1));
}

void LevelMenu::setStartLevel(int level) {
	this->game->startLevel = level;
	this->shell->exit = true;
}
