#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

#define C_BLACK 0
#define C_WHITE 7
#define C_GRAY 8
#define C_LAQUA 11
#define C_LPURPLE 13

static void log(std::string message) {
	std::cout << message << std::endl;
}

static void printAt(std::string text, SHORT x, SHORT y) {
	static auto output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output_handle, { x, y });

	std::cout << text;
}

static void printAt(char character, SHORT x, SHORT y) {
	static auto output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output_handle, { x, y });

	std::cout << character;
}

// Set console text colour (foreground and background)
static void setCol(WORD fg, WORD bg = C_BLACK) {
	static auto output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(output_handle, fg | (bg*16));
}
