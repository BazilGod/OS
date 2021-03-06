#include "stdafx.h"
#include <iostream>
#include "Windows.h"
#include <string>
#include <fstream>
#include <conio.h>
 using namespace std;
int chose;

void CreateDir();
void Text();
void Copy();
void Deleted();
void Move();
void Read();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите:" << std::endl;
	std::cout << "1-для создания двух папок                                   " << std::endl;
	std::cout << "2-для создания текстового файла и записи в него в 1 каталоге" << std::endl;
	std::cout << "3-для копирования файла из 1 каталога во 2                  " << std::endl;
	std::cout << "4-для удаления файла из 1 каталога                          " << std::endl;
	std::cout << "5-для для переименования файла                              " << std::endl;
	std::cout << "6-для для чтения его содержимого                            " << std::endl;
	std::cout << "7-для выхода                                                " << std::endl;
	std::cout << "____________________________________________________________" << std::endl;
	std::cin >> chose;
	do
	{
		switch (chose)
		{
		case 1:
			CreateDir();
			break;
		case 2:
			Text();
			break;
		case 3:
			Copy();
			break;
		case 4:
			Deleted();
			break;
		case 5:
			Move();
			break;
		case 6:
			Read();
			break;
		}
	} while (chose != 7);

	return 0;
}

void CreateDir() {
	TCHAR Buffer2[] = TEXT("d:\\1");
	TCHAR Buffer3[] = TEXT("d:\\2");

	CreateDirectory(Buffer2, NULL);

	CreateDirectory(Buffer3, NULL);
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "Что дальше?" << std::endl;
	std::cin >> chose;
}

void Text() {
	TCHAR Buffer[256] = TEXT("Sozdano");
	HANDLE hOut;
	DWORD dwNumberOfBytes;

	TCHAR stdPath[30] = TEXT("d:\\1\\file.txt");
	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE) {
		std::cout << "Ошибка %x \n" << std::endl;
		getchar();
	}

	else
	{
		WriteFile(hOut, Buffer, 256, &dwNumberOfBytes, NULL);
		std::cout << "Создано и записано" << std::endl;
		getchar();
		CloseHandle(hOut);
	}
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "Что дальше?" << std::endl;
	std::cin >> chose;
}
															
void Copy() {
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;


	TCHAR filea[30] = TEXT("d:\\1\\file.txt");
	TCHAR fileb[30] = TEXT("d:\\2\\file.txt");

	BOOL pr = CopyFile(filea, fileb, NULL);
	if (pr)
	{
		std::cout << "Скопировано" << std::endl;
		getchar();
	}
	else
	{
		std::cout << "Не скопировано(" << std::endl;
		getchar();
	}

	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "Что дальше?" << std::endl;
	std::cin >> chose;
}

void Deleted() {
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;

	TCHAR file[30] = TEXT("d:\\1\\file.txt");
	BOOL pr = DeleteFile(file);
	if (pr)
	{
		std::cout << "Удалено" << std::endl;
		getchar();
	}
	else
	{
		std::cout << "Не удалено(" << std::endl;
		getchar();
	}

	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "Что дальше?" << std::endl;
	std::cin >> chose;
}

void Move() {
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;
	BOOL pr2 = 0;

	TCHAR fileA[30] = TEXT("d:\\2\\file.txt");
	TCHAR fileB[30] = TEXT("d:\\2\\newfile.txt");

	BOOL pr = MoveFile(fileA, fileB);
	if (pr)
	{
		std::cout << "Переименовано" << std::endl;
		getchar();

	}
	else
	{
		std::cout << "Не переименовано(" << std::endl;
		getchar();
	}
	std::cout << "____________________________________________________________" << std::endl;
	std::cout << "Что дальше?" << std::endl;
	std::cin >> chose;
}

void Read() {
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;

	TCHAR file[30] = TEXT("d:\\2\\newfile.txt");

	hIn = CreateFile(file, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE) {
		std::cout << "Данные не прочитаны(" << std::endl;
		getchar();
	}

	else
	{
		ReadFile(hIn, Buffer, 256, &dwNumberOfBytes, NULL);
		std::cout << "Данные успешно прочитаны" << std::endl;
		std::wcout << Buffer << std::endl;
		getchar();
		CloseHandle(hIn);
	}
	

	cin.get();

	std::cout << "\nЧто дальше?" << std::endl;
	std::cin >> chose;
}
