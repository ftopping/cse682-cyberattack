#include "level.hh"
#include "shell.hh"

Level::Level() {
}

Level::~Level() {
}

bool Level::main() {
	Shell shell(this->name, this->welcome);
	shell.main();

	return false;
}
