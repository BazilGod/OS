#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"
#include <iomanip>
char probel = ' ';

const WORD colors[] =
{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	HANDLE consoleOutput;
	COORD cursorPos;

	// Получаем хэндл консоли 
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleOutput, &csbi);

		cursorPos.X = 30;
		cursorPos.Y = 5;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		SetConsoleTextAttribute(consoleOutput, 0x3C);
		std::cout << "_______________________________________" << std::endl;

		cursorPos.X = 30;
		cursorPos.Y = 6;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		SetConsoleTextAttribute(consoleOutput, 0x5E);
		std::cout << "|ФАМИЛИЯ          |ГРУППА             |" << std::endl;

		cursorPos.X = 30;
		cursorPos.Y = 7;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		SetConsoleTextAttribute(consoleOutput, 0x5E);
		std::cout << "|_________________|___________________|" << std::endl;


		cursorPos.X = 30;
		cursorPos.Y = 8;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		SetConsoleTextAttribute(consoleOutput, 0xF6);
		std::cout << "|Иконов           |4                 |" << std::endl;

		cursorPos.X = 30;
		cursorPos.Y = 9;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		SetConsoleTextAttribute(consoleOutput, 0x1A);
		std::cout << "|_________________|___________________|" << std::endl;

	
	return 0;
}

