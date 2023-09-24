#include <iostream>
#include <vector>

#include "instructions.hpp"
#include "parser.hpp"

namespace inst {
	/* Prints to standard out */
	int print (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++)
			std::cout << args[i];
		return 0;
	}

	/* Prints to standard out with newline */
	int print_l (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++)
			std::cout << args[i];
		std::cout << '\n';
		return 0;
	}

	/* Prints to standard error stream */
	int print_e (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++)
			std::cerr << args[i];
		return 0;
	}

	/* Prints to standard error stream with newline */
	int print_el (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++)
			std::cerr << args[i];
		std::cerr << '\n';
		return 0;
	}

	int jump (std::vector<std::string>& args) {
		size_t line = atoi(args[0].c_str());
		parser::read_line(parser::fmap[line], line);
		return 0;
	}

	int compare (std::vector<std::string>& args) {
		return 0;
	}
}
