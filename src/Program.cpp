#include "Program.h"

#include <fstream>
#include "helpers.h"

Program::Program(std::string filename) {
	// Field initialization
	loaded_ = false;
	ip_x_ = ip_y_ = 0;

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

void Program::print(SHORT x, SHORT y) const {
	setCol(C_GRAY);

	for (auto i = 0; i < lines_.size(); i++) {
		for (auto j = 0; j < lines_[i].length(); j++) {
			// If the current character is at the Instruction Pointer, print it in colour
			if (i == ip_x_ && j == ip_y_) {
				setCol(C_LAQUA);
			}

			printAt(lines_[i][j], y+j, x+i);

			if (i == ip_x_ && j == ip_y_) {
				setCol(C_GRAY);
			}
		}
	}
}
