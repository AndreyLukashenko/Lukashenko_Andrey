#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <iostream>
#include <Windows.h>

#include "Constants.hpp"

class ConsoleUI
{
public:
	ConsoleUI();
	ConsoleUI(const ConsoleUI&) = delete;
	ConsoleUI& operator=(const ConsoleUI&) = delete;
	~ConsoleUI();

	static std::shared_ptr<ConsoleUI> getInstance();
	void clearInputBuffer();
	void render();

	void setChar(int x, int y, wchar_t c, COLOR color);
	wchar_t getChar(int x, int y) const;
	
private:
	HANDLE                            console_;
	HANDLE							  consoleIn_;

	CHAR_INFO* buffer_;
	COORD						      bufferCoord_;
	COORD							  bufferSize_;
	SMALL_RECT						  writeRegion_;
	
};

#endif // !CONSOLE_UI_H







