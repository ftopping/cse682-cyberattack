#include "command.hh"

#include <iostream>

Command::Command() {
}

Command::~Command() {
}

void Command::start() {
	// Subclass for code to reset any internal state.
}

int Command::main(int argc, char ** argv) {
	std::cout << "Internal Error: Unimplemented main:" << std::endl;
	std::cout << "  [" << argc << "]:\n";
	for (int i = 0; i < argc; i++) {
		std::cout << "    [" << i << "]: " << argv[i] << std::endl;
	}
	return 0;
}
