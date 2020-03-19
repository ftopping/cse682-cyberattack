#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>

#include "menu.hh"

#include "menu/commands/level.hh"

LevelMenu::LevelMenu(Game * game, int levels) {
	this->game = game;
	this->name = "menu";
	this->levels = levels;

	for (int i = 1; i <= levels; i++) {
		this->commands.push_back(new LevelMenuCommandLevel(this, i));
	}
}

std::string LevelMenu::welcome() {
	std::string levelS = std::to_string(this->game->finishedLevel);
	std::string welcome =
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
		"You are currently a level " + levelS + " hacker."
		"\n"
		"\n";

	if (game->finishedLevel < this->levels) {
		std::string l = std::to_string(game->finishedLevel + 1);
		std::string c = game->finishedLevel ? "continue" : "start";
		welcome +=
			"Enter 'level" + l + "' to " + c +
			" your adventure and level up...";
	}
	else {
		welcome +=
			"Thanks for playing this demo of CyberAttack!\n"
			"You have successfully passed all the levels currently available.";
	}
	return welcome;
}

int LevelMenu::finishedLevel() {
	// Block which collects the current filepath and appends our saveFile to the end.
    // Requires windows.h & shlobj.h
    CHAR my_documents[MAX_PATH];
    HRESULT result = SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);
    std::string filepath; 
    filepath += my_documents;
    filepath += "\\saveFile.txt";
	
	// Create a temp variable to add 1 so the game starts at the next level once 
	// it restarts.
	int level = this->game->finishedLevel + 1;
	
	// Writes the temp variable to file. If file exists it is overwritten.
	// Requires fstream
	std::ofstream saveFile;
    saveFile.open(filepath);
    saveFile << level;
    saveFile.close();
	
	return this->game->finishedLevel;
}

void LevelMenu::setStartLevel(int level) {
	this->game->startLevel = level;
	this->shell->exit = true;
}
