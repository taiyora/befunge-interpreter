#include "Program.h"

#include <fstream>
#include "helpers.h"

Program::Program(std::string filename) {
	// Field initialization
	loaded_ = false;

	// Load the data from the specified file
	std::ifstream file(filename);

	if (!file.is_open()) {
		log("Failed to open " + filename + " for reading");
		return;
	}

	std::string line;
	while (!file.eof()) {
		getline(file, line);
		lines_.push_back(line);
	}

	file.close();
	loaded_ = true;
}

Program::~Program() {}
