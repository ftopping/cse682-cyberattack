#pragma once

#include "../../../command.hh"

class Level1CommandLearn: public Command {
	public:
		Level1CommandLearn();
		virtual ~Level1CommandLearn();
		int main(int argc, char ** argv);
};
