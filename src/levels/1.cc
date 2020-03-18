#include "1.hh"

#include "1/commands/learn.hh"
#include "1/commands/challenge.hh"

Level1::Level1() {
	this->name = "level1";

	this->commands.push_back(new Level1CommandLearn());
	this->commands.push_back(new Level1CommandChallenge(this));
}

std::string Level1::welcome() {
	return
		"Welcome to the first level of CyberAttack!\n"
		"\n"
		"Type the 'learn' command to begin.";
}
