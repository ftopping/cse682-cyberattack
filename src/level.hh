#pragma once

#include <string>
#include <vector>

#include "command.hh"
#include "shell.hh"

class Level {
	public:
		bool won = false;

		Level();
		virtual ~Level();
		virtual bool main();

	protected:
		std::string name;
		std::string welcome;
		std::vector<Command *> commands;
		Shell * shell = nullptr;
};
