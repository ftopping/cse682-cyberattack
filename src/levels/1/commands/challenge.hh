#pragma once

#include "../../../command.hh"
#include "../../1.hh"

class Level1CommandChallenge: public Command {
	public:
		Level1CommandChallenge(Level1 * level);
		virtual ~Level1CommandChallenge();
		int main(int argc, char ** argv);

	protected:
		Level1 * level;
};
