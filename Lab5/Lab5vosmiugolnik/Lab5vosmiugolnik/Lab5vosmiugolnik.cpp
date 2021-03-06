// Lab5vosmiugolnik.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <stdio.h>
#include <windows.h>
 
int main()
{
    HWND hwnd = GetConsoleWindow(); //получаем экземпляр класса консольного окна
    HDC hdc = GetDC(hwnd); //получаем дескриптор устройства, где будем рисовать
    HBRUSH br = CreateSolidBrush(0xff33cc); //объявляем сплошную кисть фиолетового цвета 
 
      POINT pp[8];  //объявляем 6 структур POINT для хранения координат
 
	  pp[0].x = 75; pp[0].y = 25;  //заполняем
	  pp[1].x = 150; pp[1].y = 25;
	  pp[2].x = 200; pp[2].y = 75;
	  pp[3].x = 200; pp[3].y = 150;
	  pp[4].x = 150;  pp[4].y = 200;
	  pp[5].x = 75;  pp[5].y = 200;
	  pp[6].x = 25;  pp[6].y = 150;
	  pp[7].x = 25;  pp[7].y = 75;

      SelectObject(hdc, br); //назначаем кисть принимающему устройству
      Polygon(hdc, pp, 8);  //рисуем полигон, hdc - указывает где рисовать, &pp - указатель на массив структур POINT, 6 - количество точек
 
      system("pause"); //не даем закрыться консоли до нажатия клавиши
 
    return 0;
}