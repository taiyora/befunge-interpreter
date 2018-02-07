#include <string>

#include "helpers.h"
#include "Program.h"

int main(int argc, char* args[]) {
	system("cls");

	if (argc <= 1) {
		log("Filename argument required. Exiting...");
		return 0;
	}

	std::string filename = args[1];
	Program program(filename);

	if (!program.isLoaded()) {
		log("Exiting...");
		return 0;
	}

	program.print(0, 0);

	return 0;
}
