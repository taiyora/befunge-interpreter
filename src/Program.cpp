#include "Program.h"

#include <fstream>
#include "helpers.h"

Program::Program(std::string filename) {
	// Field initialization
	loaded_ = false;

	filename_ = filename;
	max_width_ = 0;

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

		if (line.length() > max_width_) {
			max_width_ = line.length();
		}
	}

	file.close();
	loaded_ = true;
}

Program::~Program() {}

void Program::print(SHORT x, SHORT y) const {
	// Print the filename of the program, and its size
	setCol(C_WHITE);
	printAt(filename_, x, y);

	std::string size = std::to_string(max_width_) + "x" + std::to_string(lines_.size() - 1);
	setCol(C_LPURPLE);
	printAt(size, x + filename_.length() + 1, y);

	y += 2;

	// Print the program code
	setCol(C_GRAY);

	for (auto i = 0; i < lines_.size(); i++) {
		for (auto j = 0; j < lines_[i].length(); j++) {
			// If the current character is at the Instruction Pointer, print it in colour
			if (i == ip_x_ && j == ip_y_) {
				setCol(C_LAQUA);
			}

			printAt(lines_[i][j], x+j, y+i);

			if (i == ip_x_ && j == ip_y_) {
				setCol(C_GRAY);
			}
		}
	}
}
