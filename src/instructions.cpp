#include <iostream>
#include <vector>

#include "instructions.hpp"
#include "parser.hpp"

namespace inst {
	/* Prints to standard out */
	int print (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++) {
			std::cout << args[i];
			std::cout << ' ';
		}
		return 0;
	}

	/* Prints to standard out with newline */
	int print_l (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++) {
			std::cout << args[i];
			std::cout << ' ';
		}
		std::cout << '\n';
		return 0;
	}

	/* Prints to standard error stream */
	int print_e (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++) {
			std::cerr << args[i];
			std::cerr << ' ';
		}
		return 0;
	}

	/* Prints to standard error stream with newline */
	int print_el (std::vector<std::string>& args) {
		for (size_t i = 1; i < args.size(); i++) {
			std::cerr << args[i];
			std::cerr << ' ';
		}
		std::cerr << '\n';
		return 0;
	}

	/* Scans a line string input from stdin line */
	int scan (std::vector<std::string>& args) {
		std::string line;
		std::getline(std::cin, line);
		
		parser::varmap[args[1]] = line;
		return 0;
	}

	/* Jumps to specified line in the file */
	int jump (std::vector<std::string>& args) {
		size_t line = 0;

		for (size_t i = 0; args[1][i]; i++)	
			if (!isdigit(args[1][i])) {
				std::cerr << "ERROR: call to jmp needs interger\n";
				return 1;
			}

		line = atoi(args[1].c_str());
		parser::read_line(parser::fmap[line]);
		return 0;
	}

	int compare (std::vector<std::string>& args) {
		std::string first, oper, last, true_stat, false_stat;
		parser::type_t first_type, last_type;
	
		/* Assign the first variable the second and the operator */	
		first = args[1];
		oper = args[2];
		last = args[3];

		/* Assign the truth statment and the false statment */
		true_stat = args[5];
		false_stat = args[7]; 

		std::cout << first << '\n' << oper << '\n' << last << '\n';
		std::cout << "if true " << true_stat << '\n' << "if false " << false_stat << '\n';

		/* Determine the types of the first & last arg */
		first_type = parser::get_type(first);
		last_type = parser::get_type(last);

		if (first_type != last_type) {
			std::cerr << "ERROR: Cannot compare type "
				<< first_type << " to type " << last_type << '\n';
			return 1;
		}

		return 0;
	}
}
