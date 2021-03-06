// Server.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	HANDLE hPipe;
	char buffer[1024] = "";
	DWORD dwRead;
	int retval = 0;
	hPipe = CreateNamedPipe(      // Создает экземпляр именованного канала и возвращает дескриптор для последующих операций 
		TEXT("\\\\.\\pipe\\Pipe"),// Уникальное название
		PIPE_ACCESS_DUPLEX/* Для чтения и записи*/ | PIPE_TYPE_BYTE /*передача байт */ | PIPE_READMODE_BYTE,/*Канал открывается в режиме последовательной передачи отдельных байт*/
		PIPE_WAIT,                // операции не выполняются до тех пор, пока не будут прочитаны данные, все данные записаны или клиент подключен.
		1/*кол-во каналов*/,    
		1024 * 16,                // Количество байтов для резервирования для выходного буфера.
		1024 * 16,                // Количество байтов для резервирования для входного буфера.
		NMPWAIT_USE_DEFAULT_WAIT, // Значение времени ожидания по умолчанию, в миллисекундах,
		NULL);                    // дескриптор безопасности
	while (hPipe != INVALID_HANDLE_VALUE)
	{
		std::cout << std::endl << "Ожидание клиента!\n";
		if (ConnectNamedPipe( // Позволяет процессу именованного сервера ожидать, чтобы клиентский процесс подключился к экземпляру именованного канала. 
			hPipe,            // Обработка дескриптора сервера экземпляра именованного канала.
			NULL              // Указатель на структуру OVERLAPPED асинхронном vvod i vyvod
		) != FALSE)
		{
			while (1) {
				retval = ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
				if (retval)
				{
					buffer[dwRead] = '\0';
					std::cout << "Client: " << buffer << std::endl;
				}
				else
				{
					std::cout << "Unable to write\n";
					return 1;
				}
				std::string userBuff = "";
				std::cout << "Enter text: ";
				std::getline(std::cin, userBuff);
				retval = WriteFile(hPipe, userBuff.c_str(), userBuff.length(), &dwRead, NULL);
				if (!retval)
				{
					std::cout << "Unable to write\n";
					return 1;
				}
			}
		}
		DisconnectNamedPipe(hPipe); // Отключает конец сервера экземпляра именованного канала из клиентского процесса.
	}
	return 0;
}

