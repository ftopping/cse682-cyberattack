#pragma once

#include <string>
#include <vector>

#include "command.hh"
#include "shell.hh"

class Level {
	public:
		/**
		 * Flag for if challenge is passed.
		 */
		bool won = false;

		/**
		 * Constructor.
		 */
		Level();

		/**
		 * Destructor.
		 */
		virtual ~Level();

		/**
		 * Get welcome text for the shell.
		 *
		 * @returns Welcome text.
		 */
		virtual std::string welcome();

		/**
		 * Run level.
		 *
		 * @returns Returns true if challenge is beaten.
		 */
		virtual bool main();

	protected:
		/**
		 * Level name.
		 */
		std::string name;

		/**
		 * Shell commands.
		 */
		std::vector<Command *> commands;

		/**
		 * Shell instance.
		 */
		Shell * shell = nullptr;
};
