#pragma once

#include <string>
#include <vector>

// Loads a Befunge program from the specified file and manages it
class Program {
	bool loaded_;
	std::vector<std::string> lines_;

public:
	Program(std::string filename);
	~Program();
};
