#pragma once

#include "../../../command.hh"

class Level1CommandChallenge: public Command {
	public:
		Level1CommandChallenge();
		virtual ~Level1CommandChallenge();
		int main(int argc, char ** argv);
};
