#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include "string.h"
#include "conio.h"

using namespace std;
ifstream file("D:/5sem/os/Lab17_password/output.txt");
char  password[5];
int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Input password:";
	char ch;
	file.getline(password, 6);
	file.close();
	int i = 0;
	bool priz = true;
	while (i<5)
	{
		ch = _getch();
		switch (i)
		{
		case 0:
			if (!(ch == password[i]))
				priz = false;
			break;
		case 1:
			if (!(ch == password[i]))
				priz = false;
			break;
		case 2:
			if (!(ch == password[i]))
				priz = false;
			break;
		case 3:
			if (!(ch == password[i]))
				priz = false;
			break;
		case 4:
			if (!(ch == password[i]))
				priz = false;
			break;
		}
		ch = '*';		
		printf("%c", ch );
		i++;
	}
	if (priz)
	{
		cout << "\nOK!" << std::endl;
	}
	else
	{
		cout << "\nWrong password!" << std::endl;
	}
	return 0;
}
