#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#include "parser.hpp"
#include "config.hpp"
#include "instructions.hpp"

namespace parser {
	struct INSTRUCTION_MAP {
		std::string instruction;
		int (*function)(std::vector<std::string>& args);
		size_t argc;
	};

	const size_t imap_max = 7;
	struct INSTRUCTION_MAP imap[imap_max] = {
		{ "jmp", inst::jump, 1 },
		{ "cmp", inst::compare, 3 },
		{ "_scan", inst::scan, 1 },
		{ "_print", inst::print, 1},
		{ "_print_l", inst::print_l, 1},
		{ "_print_e", inst::print_e, 1},
		{ "_print_el", inst::print_el, 1 },
	};

	std::vector<std::string> split_string (std::string line, const char delim) {
		std::vector<std::string> vec;
		std::istringstream iss(line);
		std::string tmp;

		/* Split string by delim char */
		while (std::getline(iss, tmp, delim))
			vec.push_back(tmp);

		return vec;
	}

	/* See's if a string is a valid instruction */
	ssize_t is_instruction (std::string cmd) {
		for (size_t i = 0; i < parser::imap_max; i++)
			if (cmd == parser::imap[i].instruction)
				return i;
		return -1;
	}

	/* See's if char is a comment */
	int is_comment (const char c) {
		if (c == COMMENT_CHAR)
			return 1;

		return 0;
	}

  /* Checks if the amount of args is valid */
	bool valid_argc (size_t argc, size_t imap_index) {
		size_t imap_argc = parser::imap[imap_index].argc;

		if (imap_argc > argc) {
			// TODO 
			std::cerr << "ERROR: Expected " << imap_argc << " args, for " << 
									" instruction, got "
									<< argc << '\n';
			return false;
		}
		
		if (imap_argc < argc) {
			std::cerr << "ERROR: Too many args for instruction " <<
									parser::imap[imap_index].instruction <<
									" expected " << parser::imap[imap_index].argc <<
									" got " << argc << '\n';
			return false;
		}

		return true;
	}

	int get_context (std::vector<std::string> args, size_t imap_index) {
		size_t argc = args.size() - 1;

		/* Make sure the arg counts match */
		if (!parser::valid_argc(argc, imap_index))
			return 1;
	
		if (parser::imap[imap_index].function(args))
			return 1;

		return 0;
	}

	int read_line (std::string line) {
		std::vector<std::string> args;
		std::string cmd;
		size_t imap_index;

		args = parser::split_string(line, ' ');

		/* Do nothing if it's a comment */
		if (parser::is_comment(args[0][0]))
			return 0;

		parser::remove_comments(args);
		cmd = args[0];

		/* Make sure the instruction is valid */
		if ((imap_index = is_instruction(cmd)) == -1) {
			std::cerr << "ERROR: No such instruction " << cmd << '\n';
			return 1;
		}

		if (parser::get_context(args, imap_index))
			return 1;

		return 0;
	}

	void remove_comments (std::vector<std::string>& line) {
	}
}
