#include "learn.hh"

#include <iostream>

Level1CommandLearn::Level1CommandLearn() {
	this->name = "learn";
}

Level1CommandLearn::~Level1CommandLearn() {
}

int Level1CommandLearn::main(int argc, char ** argv) {
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
			"Good idea, but the input is filtered." <<
			std::endl;
		return 0;
	}

	// Parse integer, can overflow, by design.
	int32_t yourNumber;
	sscanf(num, "%d", &yourNumber);

	int32_t myNumber = 0;
	std::cout << "My number: " << myNumber << std::endl;
	std::cout << "Your number: " << yourNumber << std::endl;
	std::cout << std::endl;

	// Check for which value is smaller.
	if (yourNumber < myNumber) {
		std::cout <<
			"PASS: Your number IS lower!" <<
			std::endl <<
			std::endl <<
			"You passed the learning stage, and unlocked a hint:" <<
			std::endl <<
			"  The challenge parses your input as a IEEE-754 float." <<
			std::endl;
	}
	else {
		std::cout <<
			"FAIL: Your number IS NOT lower than my number." <<
			std::endl <<
			std::endl <<
			"HINT: Your input is parsed as a 32-bit integer." <<
			std::endl;
	}

	return 0;
}
