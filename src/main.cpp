#include <iostream>
#include <fstream>
#include <vector>

#include "parser.hpp"
#include "instructions.hpp"

/* Opens file for reading */
int ropen_file (std::string file, std::ifstream& stream) {
	stream.open(file, std::ios::in);
	
	if (!stream.is_open()) {
		std::cerr << "ERROR: No such file " << file << '\n';
		return 1;
	}

	return 0;
}

/* Closes a file stream */
void close_file (std::ifstream& stream) {
	stream.close();
}

int read_files (std::string file) {
	std::string line;
	std::ifstream stream;

	if (ropen_file(file, stream))
		return 1;

	for (size_t ln = 0; std::getline(stream, line); ln++) {
		parser::fmap[ln] = line;
		if (parser::read_line(line))
			return 1;
	}

	close_file(stream);
	return 0;
}

/* Sets files names in vector */
void set_src (std::vector<std::string>& files, char **argv) {
	for (size_t i = 1; argv[i]; i++)
		files.push_back(argv[i]);
}

int setup (char **argv) {
	/* Holds all files passed at cmd line */
	std::vector<std::string> files;
	
	/* Set all file names in vector */
	set_src(files, argv);
	
	/* Open up file one by one for reading */
	for (size_t i = 0; i != files.size(); i++)
		if (read_files(files[i]))
			return 1;

	return 0;
}

int main (int argc, char **argv) {
	return setup(argv);
}
