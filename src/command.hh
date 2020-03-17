#pragma once

#include <string>
#include <stdexcept>

class Command {
	public:
		std::string name;

		Command();
		virtual ~Command();
		virtual void start();
		virtual int main(int argc, char ** argv);
};
