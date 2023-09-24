#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <map>

namespace parser {
	/* Holds the line number and the line contents */
	std::map<size_t, std::string> fmap;

	/* Removes comment's from a line of input */
	void remove_comments (std::vector<std::string>& line);

	/* Reads a line of input and processes it */
	int read_line (std::string line, size_t ln);
}

#include "parser.cpp"

#endif /* PARSER_HPP */
