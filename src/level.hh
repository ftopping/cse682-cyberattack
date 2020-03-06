#pragma once

#include <string>

class Level {
	public:
		std::string name;
		std::string welcome;

		Level();
		virtual ~Level();
		virtual bool main();
};
