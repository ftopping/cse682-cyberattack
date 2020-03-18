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

	std::string equation = "(myNumber / yourNumber) > myNumber";

	if (argc <= 1) {
		std::cout <<
			"TODO: Learn intro." <<
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

	float yourNumber;
	sscanf(num, "%f", &yourNumber);

	float myNumber = 3.14;
	std::cout << "My number: " << myNumber << std::endl;
	std::cout << "Your number: " << yourNumber << std::endl;

	// Divide by the input, which could be 0, by design.
	float divided = myNumber / yourNumber;
	bool result = divided > myNumber;

	std::cout <<
		"Equation:" <<
		std::endl <<
		"  " << equation << " =" <<
		std::endl <<
		"  (" << myNumber << " / " << yourNumber << ") > " <<
		myNumber << " =" <<
		std::endl <<
		"  " << divided << " > " << myNumber << " =" <<
		std::endl <<
		"  " << (result ? "true" : "false") <<
		std::endl <<
		std::endl;

	if (result) {
		std::cout <<
			"PASS: My number divided by your number IS higher!" <<
			std::endl <<
			"  An IEEE-754 dividing a float by 0 results in infinity." <<
			std::endl <<
			std::endl <<
			"You passed the learning stage, and unlocked a hint:" <<
			std::endl <<
			"  The challenge reads your input as an unsigned 32-bit integer." <<
			std::endl <<
			"  Is there a way to flip that negative without a minus sign?" <<
			std::endl <<
			std::endl <<
			"Type 'challenge' to start the challenge." <<
			std::endl;
	}
	else {
		std::cout <<
			"FAIL: My number divided by your number is lower than my number." <<
			std::endl <<
			std::endl <<
			"HINT: Your input is parsed as an IEEE-754 float." <<
			std::endl;
	}

	return 0;
}
