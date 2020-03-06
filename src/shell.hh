#pragma once

#include <string>

class Shell {
	public:
		std::string host;
		std::string welcome;

		Shell(std::string host, std::string welcome);
		void main();
};
