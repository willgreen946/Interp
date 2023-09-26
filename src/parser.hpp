#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <map>

/* These are to be used with the type_t */
#define INTIN 0 /* Takes an int as argument */
#define STRIN 1 /* Takes a string input */
#define IFIN 2 /* A conditional if statment */

namespace parser {
	/* Types of instruction see defines above*/
	typedef unsigned short type_t;

	/* A map to hold variables */
	std::map<std::string, std::string> varmap;

	/* Holds the line number and the line contents */
	std::map<size_t, std::string> fmap;

	/* Removes comment's from a line of input */
	void remove_comments (std::vector<std::string>& line);

	/* Removes whitespace chars ' ' and '\t' from std::string */
	void trim_whitespace (std::string& str);
	
	/* Gets type of variable from string */
	parser::type_t get_type (std::string var);

	/* Reads a line of input and processes it */
	int read_line (std::string line);
}

constexpr parser::type_t INT_T = 0;
constexpr parser::type_t CHAR_T = 1;
constexpr parser::type_t STRING_T = 2;

#include "parser.cpp"

#endif /* PARSER_HPP */
