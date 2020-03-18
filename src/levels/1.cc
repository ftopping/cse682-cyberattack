#include "1.hh"

#include "1/commands/learn.hh"
#include "1/commands/challenge.hh"

Level1::Level1() {
	this->name = "level1";
	this->welcome = "TODO: Welcome message.";

	this->commands.push_back(new Level1CommandLearn());
	this->commands.push_back(new Level1CommandChallenge());
}
