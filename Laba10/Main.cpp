#pragma comment(linker,"/manifestdependency:\"type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "resource.h";

HWND hWnd;
HINSTANCE hInst;



LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInst = hInstance;
	MSG lpMsg;
	WNDCLASS wc;
	LPCWSTR szClassName = L"CG_WAPI_Template";

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szClassName;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, L"Не можу зареєструвати клас вікна!", L"Помилка", MB_OK);
		return 0;
	}
	int width = 600, height = 600;

	HWND hWnd = CreateWindowW(
		szClassName,
		L"Лабораторна робота 10",
		WS_OVERLAPPEDWINDOW,
		(GetSystemMetrics(SM_CXSCREEN) - width) / 2, (GetSystemMetrics(SM_CYSCREEN) - height) / 2,
		width, height,
		NULL,
		NULL,
		(HINSTANCE)hInstance,
		NULL);

	if (!hWnd)
	{
		MessageBox(NULL, L"Не вдалося створити головне меню!", L"Помилка", MB_OK);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return (lpMsg.wParam);
}



////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	
	switch (message)
	{
	case WM_CREATE:
		
		break;
	case WM_PAINT: {		//Перемалювати вікно
		
	}
	case WM_COMMAND:
		

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, message, wParam, lParam));
		break;
	}
	return 0;
}


