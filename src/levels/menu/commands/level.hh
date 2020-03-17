#pragma once

#include "../../../command.hh"
#include "../../menu.hh"

class LevelMenuCommandLevel: public Command {
	public:
		LevelMenuCommandLevel(LevelMenu * menu, int level);
		virtual ~LevelMenuCommandLevel();
		int main(int argc, char ** argv);

	protected:
		LevelMenu * menu;
		int level;
};
