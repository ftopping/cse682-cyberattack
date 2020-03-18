#include "challenge.hh"

#include <iostream>

Level1CommandChallenge::Level1CommandChallenge(Level1 * level) {
	this->name = "challenge";
	this->level = level;
}

Level1CommandChallenge::~Level1CommandChallenge() {
}

int Level1CommandChallenge::main(int argc, char ** argv) {
	(void)argc;
	(void)argv;

	std::string equation = "yourNumber < myNumber";

	if (argc <= 1) {
		std::cout <<
			"TODO: Challenge intro." <<
			std::endl;
		return 0;
	}

	// Validate argument only has number characters.
	char * num = argv[1];
	bool dec = *num ? true : false;
	for (char * p = num; *p; p++) {
		if (*p < '0' || *p > '9') {
			dec = false;
			break;
		}
	}
	if (!dec) {
		std::cout <<
			"FAIL: Argument can only contain charaters: 0123456789" <<
			std::endl <<
			std::endl <<
			"Nice try, but I planned for that." <<
			std::endl;
		return 0;
	}

	// Parse integer, can overflow, by design.
	int32_t yourNumber;
	sscanf(num, "%d", &yourNumber);

	int32_t myNumber = 0;
	std::cout << "My number: " << myNumber << std::endl;
	std::cout << "Your number: " << yourNumber << std::endl;

	bool result = yourNumber < myNumber;

	std::cout <<
		"Equation:" <<
		std::endl <<
		"  " << equation << " =" <<
		std::endl <<
		"  " << yourNumber << " < " << myNumber << " =" <<
		std::endl <<
		"  " << (result ? "true" : "false") <<
		std::endl <<
		std::endl;

	if (result) {
		std::cout <<
			"PASS: Your number IS highed!" <<
			std::endl <<
			"  Curses, how did you beat me? I'll get you on the next level!" <<
			std::endl <<
			std::endl <<
			"Congratulations on passing the challenge!" <<
			std::endl <<
			"  Type exit to return to the menu and start the next level." <<
			std::endl;

		// Mark level as won.
		this->level->won = true;
	}
	else {
		std::cout <<
			"FAIL: Nice try, but your number is NOT lower than my number." <<
			std::endl;
	}

	return 0;
}
