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
	HANDLE consoleOutput;
	COORD cursorPos;

	//заголовок потока //ввода
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleOutput, &csbi);

	int in = 5;
	do {
		// Задаем координаты курсора и перемещаем курсор
		cursorPos.X = 10;
		cursorPos.Y = in;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		SetConsoleTextAttribute(consoleOutput, 0xA1);
		// Выводим строку

		std::cout << "              " << std::endl;

		in++;
	} while (in < 14);

	getchar();

	return 0;
}