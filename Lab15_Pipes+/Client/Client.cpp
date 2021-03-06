// Client.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	HANDLE hPipe;
	DWORD dwRead;
	DWORD dwWritten;
	char buffer[1024];
	int retval = 0;
	hPipe = CreateFile(TEXT("\\\\.\\pipe\\Pipe"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hPipe != INVALID_HANDLE_VALUE)
	{
		while (1) {
			std::string userBuff = "";
			std::cout << "Enter text: ";
			std::getline(std::cin, userBuff);
			retval = WriteFile(hPipe, userBuff.c_str(), userBuff.length(), &dwRead, NULL);
			if (!retval)
			{
				std::cout << "Unable to write\n";
				return 1;
			}
			retval = ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
			if (retval)
			{
				buffer[dwRead] = '\0';
				std::cout << "Server: " << buffer << std::endl;
			}
			else
			{
				std::cout << "Unable to read\n";
				return 1;
			}
		}
		CloseHandle(hPipe);
	}
	return 0;
}
