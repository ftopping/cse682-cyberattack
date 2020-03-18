#include "menu.hh"

#include "menu/commands/level.hh"

LevelMenu::LevelMenu(Game * game, int levels) {
	this->game = game;
	this->name = "menu";

	std::string levelS = std::to_string(game->finishedLevel);
	this->welcome =
		"Welcome to...\n\n"
"   _____      _                     _   _             _     \n"
"  / ____|    | |               /\\  | | | |           | |    \n"
" | |    _   _| |__   ___ _ __ /  \\ | |_| |_ __ _  ___| |__  \n"
" | |   | | | | '_ \\ / _ \\ '__/ /\\ \\| __| __/ _` |/ __| '_ \\ \n"
" | |___| |_| | |_) |  __/ | / ____ \\ |_| || (_| | (__| | | |\n"
"  \\_____\\__, |_.__/ \\___|_|/_/    \\_\\__|\\__\\__,_|\\___|_| |_|\n"
"         __/ |                                              \n"
"        |___/                                               \n"
		"\n"
		"You are currently a level " + levelS + " hacker.";

	for (int i = 1; i <= levels; i++) {
		this->commands.push_back(new LevelMenuCommandLevel(this, i));
	}

	if (game->finishedLevel < levels) {
		std::string l = std::to_string(game->finishedLevel + 1);
		std::string c = game->finishedLevel ? "continue" : "start";
		this->welcome +=
			"\n"
			"\n"
			"Type 'level" + l + "' to " + c + " your adventure and level up...";
	}
}

int LevelMenu::finishedLevel() {
	return this->game->finishedLevel;
}

void LevelMenu::setStartLevel(int level) {
	this->game->startLevel = level;
	this->shell->exit = true;
}
