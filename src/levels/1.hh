#pragma once

#include "1.hh"
#include "../level.hh"

class Level1: public Level {
	public:
		/**
		 * Constructor.
		 */
		Level1();

		/**
		 * Get welcome text for the shell.
		 *
		 * @returns Welcome text.
		 */
		virtual std::string welcome();
};
