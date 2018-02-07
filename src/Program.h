#pragma once

#include <string>
#include <vector>
#include <Windows.h>

// Loads a Befunge program from the specified file and manages it
class Program {
	bool loaded_;

	std::string filename_;
	std::vector<std::string> lines_;
	unsigned short max_width_;

	// Instruction Pointer
	unsigned short ip_x_, ip_y_;

public:
	Program(std::string filename);
	~Program();

	void print(SHORT x, SHORT y) const;

	bool isLoaded() const { return loaded_; }
};
