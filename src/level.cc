#include "level.hh"

Level::Level() {
}

Level::~Level() {
	for (auto command : this->commands) {
		delete command;
	}
	this->commands.clear();
}

std::string Level::welcome() {
	return "";
}

bool Level::main() {
	this->shell = new Shell(this->name, this->welcome());

	for (auto command : this->commands) {
		this->shell->addCommand(command);
	}
	this->shell->main();

	delete this->shell;

	return this->won;
}
