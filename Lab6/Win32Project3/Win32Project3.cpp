#include "stdafx.h" 
#include "Win32Project3.h" 
#include <string.h> 
#include <stdio.h> 
#include "Resource.h" 


#define IDC_MYICON 2 
#define IDD_WINCW_DIALOG 102 
#define IDD_ABOUTBOX 103 
#define IDS_APP_TITLE 103 
#define IDM_ABOUT 104 
#define IDM_EXIT 105 
#define IDS_HELLO 106 
#define IDI_WINCW 107 
#define IDI_SMALL 108 
#define IDC_WINCW 109 
#define IDC_WMCHAR 110 
#define IDR_MAINFRAME 128 
#define IDC_STATIC -1 
#define IDD_DIALOG1 119 
// Next default values for new objects 
// 
#ifdef APSTUDIO_INVOKED 
#ifndef APSTUDIO_READONLY_SYMBOLS 
#define _APS_NEXT_RESOURCE_VALUE 129 
#define _APS_NEXT_COMMAND_VALUE 32771 
#define _APS_NEXT_CONTROL_VALUE 1000 
#define _APS_NEXT_SYMED_VALUE 110 
#endif 
#endif 


#define MAX_LOADSTRING 100 

// Global Variables: 
HINSTANCE hInst; // current instance 
TCHAR szTitle[MAX_LOADSTRING]; // The title bar text 
TCHAR szWindowClass[MAX_LOADSTRING]; // the main window class name 
int colmn = 1, abc = 1;

// Forward declarations of functions included in this code module: 
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK myF(HWND, UINT, WPARAM, LPARAM); //объявим диалоговую процедуру в программе:myF


int APIENTRY _tWinMain( //Одной из первых задач функции _tWinMain является вызов метода регистрации оконного класса-MyRegisterClass(hInstance);                                            
	HINSTANCE hInstance,  // создаём дескриптор окна
    HINSTANCE hPrevInstance,  // описываем класс окна
	LPTSTR lpCmdLine,	
	int nCmdShow)  // возвращаем значение при неудаче или при выходе
				   //Параметр LPSTR  lpCmdLine, есть указатель на строку, содержащую аргументы, переданные программе при ее запуске из командной
	                                                                     //строки. Параметр          int nCmdShow  задает способ отображения окна.
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here. 
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings 
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT3, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT3));

	// Main message loop: 
	while (GetMessage(&msg, NULL, 0, 0))//В данном цикле считывается сообщение из очереди сообщений GetMessage.
	{   //Затем вызов TranslateAccelerator осуществляет трансляцию клавиш, нажатых на клавиатуре и отправляет сообщение msg в оконную процедуру 
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))                                                   //посредством DispatchMessage.
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



// 
// FUNCTION: MyRegisterClass() 
// 
// PURPOSE: Registers the window class. 
// 
// COMMENTS: 
// 
// This function and its usage are only necessary if you want this code 
// to be compatible with Win32 systems prior to the 'RegisterClassEx' 
// function that was added to Windows 95. It is important to call this function 
// so that the application will get 'well formed' small icons associated 
// with it. 
// 
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW; //Задаем стиль окна.
	wcex.lpfnWndProc = WndProc; //Определяет имя оконной процедуры.
	wcex.cbClsExtra = 0; //Дополнительные данные для класса.
	wcex.cbWndExtra = 0;//Дополнительные данные для окна.
	wcex.hInstance = hInstance; //Заголовок приложения, работающего с данным окном.
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT3)); //Иконка для окна приложения.
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); //Устанавливает тип курсора в окне приложения.
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //Задает кисть для закраски окна.
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT3); //Задает меню для окна приложения.
	wcex.lpszClassName = szWindowClass; //Указатель на оконный класс.
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); //Это описание используется для регистрации оконного класса с помощью 
	                                       //вызова функции RegisterClassEx(&wcex); Вызов этой функции вложен в метод MyRegisterClass(hInstance);

	return RegisterClassEx(&wcex);
}

// 
// FUNCTION: InitInstance(HINSTANCE, int) 
// 
// PURPOSE: Saves instance handle and creates main window 
// 
// COMMENTS: 
// 
// In this function, we save the instance handle in a global variable and 
// create and display the main program window. 
// 
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) //осуществляет инициализацию приложения и формирует дескриптор приложения hInstance.
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable 

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, //Данная процедура  в свою очередь создает окно приложения путем вызова CreateWindow.
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	HBRUSH hbrush = CreateSolidBrush(RGB(20, 220, 255)); // ------------ цвет
	SetClassLongPtr(hWnd, -10, (LONG)hbrush);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// 
// FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM) 
// 
//

// 
// WM_COMMAND - process the application menu 
// WM_PAINT - Paint the main window 
// WM_DESTROY - post a quit message and return 
// 
// 
LRESULT CALLBACK WndProc(HWND hWnd, // дескриптор окошка

	UINT message,  // сообщение, посылаемое ОС
	WPARAM wParam, 	 // параметры
	LPARAM lParam       // сообщений, для последующего обращения
)

{
	HBRUSH hbrush = CreateSolidBrush(RGB(20, 220, 255)); // ------------ цвет
	int wmId, wmEvent;
	PAINTSTRUCT ps; //в структуре информация об окне для прорисовки
	HDC hdc;

	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	TCHAR str[] = TEXT("BIG MAG");
	int responce = 0;
	hdc = GetDC(hWnd); // посмотреть потом
	TextOut(hdc, 355, colmn + 232, TEXT(" "), 2);
	TextOut(hdc, 355, colmn + 248, TEXT(" "), 2);
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections: 
		switch (wmId)
		{

		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;


		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_RBUTTONDOWN:
		responce=MessageBox(hWnd,TEXT("Choose action"),TEXT("Right Button"),MB_YESNO);

		switch(responce)
		

		{
		case IDYES:MessageBox(hWnd,TEXT("Choose YES-S"),TEXT("Right Button"),MB_OK);

		break;
		case IDNO:MessageBox(hWnd,TEXT("Choose NO-O"),TEXT("Right Button"),MB_OK);
		break;
		}
		 DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About); 
		break;

	case WM_KEYDOWN:
		switch (wParam) {
		case VK_SHIFT:
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
			hdc = GetDC(hWnd); // посмотреть потом
			SetBkColor(hdc, RGB(100, 11, 100));
			SetTextColor(hdc, RGB(255, 255, 255));
			//TextOut(hdc, abc, colmn, TEXT(""), 7); //Здесь используется переменная column(номер строки для рисования текста)
			//TextOut(hdc, abc += 5, colmn, TEXT(""), 7);//дескриптор контекста устройства,x-коррдината,y-координата,строка символов,число символов
			abc += 7;
	      	//TextOut(hdc, abc + 20, colmn, TEXT(" "), 7);//Функция TextOut записывает строку символов в заданном месте
			
			TextOut(hdc, abc + 5, colmn + 16, str, 7);
			ReleaseDC(hWnd, hdc);
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here... 
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK myF(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)

		{
			int z = MessageBoxEx(NULL, TEXT("HELLO"), TEXT("DialogWin"), MB_OK, 0x0409);
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}

		break;
	}
	return FALSE;
}



// Message handler for about box. 
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
