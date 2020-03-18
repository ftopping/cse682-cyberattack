#include "challenge.hh"

#include <iostream>

Level1CommandChallenge::Level1CommandChallenge() {
	this->name = "challenge";
}

Level1CommandChallenge::~Level1CommandChallenge() {
}

int Level1CommandChallenge::main(int argc, char ** argv) {
	(void)argc;
	(void)argv;

	if (argc <= 1) {
		std::cout <<
			"TODO: Introduction." <<
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

	float yourNumber;
	sscanf(num, "%f", &yourNumber);

	float myNumber = 42;
	std::cout << "My number: " << myNumber << std::endl;
	std::cout << "Your number: " << yourNumber << std::endl;

	float divided = myNumber / yourNumber;
	std::cout << "My number divided by your number: " << divided << std::endl;
	std::cout << std::endl;

	if (divided > myNumber) {
		std::cout <<
			"PASS: Your number IS highed!" <<
			std::endl <<
			std::endl <<
			"Curses, how did you beat me? I'll get you on the next level!" <<
			std::endl <<
			std::endl <<
			"Congratulations on passing the challenge! "
			"Type exit to return to the menu and start the next level." <<
			std::endl;

		// TODO: Mark level as won...
	}
	else {
		std::cout <<
			"FAIL: Nice try, but your number is lower." <<
			std::endl;
	}

	return 0;
}
