#include "level.hh"

Level::Level() {
}

Level::~Level() {
}

bool Level::main() {
	this->shell = new Shell(this->name, this->welcome);

	for (auto command : this->commands) {
		this->shell->addCommand(command);
	}
	this->shell->main();

	delete this->shell;

	return this->won;
}
