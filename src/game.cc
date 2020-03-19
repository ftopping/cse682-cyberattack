#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>

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
		
		// Searches for the current user documents library and appends our saveFile.txt to the end for
		// the filepath string used later.
    	// Requires windows.h & shlobj.h
    	CHAR my_documents[MAX_PATH];
    	HRESULT result = SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);
    	std::string filepath; 
   		filepath += my_documents;
    	filepath += "\\saveFile.txt";

		// This checks if a file exists. If it does it pulls the value and stores in startLevel. 
		// If it doesn't we set startLevel to 0 and continue.
		// Requires fstream
		struct stat buf;
   		if (stat(filepath.c_str(), &buf) != -1) {
        	std::ifstream saveFile;
        	saveFile.open(filepath);
			int level;
        	saveFile >> level;
			this->startLevel = level;
        	saveFile.close();
    	}
    	else {
        	this->startLevel = 0;
    	}

		Level * level = this->levels.at(startLevel);
		bool won = level->main();

		// Maybe update finished levels.
		if (won && startLevel > this->finishedLevel) {
			this->finishedLevel = startLevel;
		}
	}
}
