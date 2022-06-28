
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


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static STARTUPINFO sInfo;
	static PROCESS_INFORMATION pInfo;

	switch (message)
	{
	case WM_CREATE:

		break;

	case WM_COMMAND:
		ZeroMemory(&sInfo, sizeof(sInfo));
		sInfo.cb = sizeof(sInfo);
		ZeroMemory(&pInfo, sizeof(pInfo));
		switch (LOWORD(wParam)) {
		case 40013:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 5 балів \nКоль Е.В. - 3.7 балів \nСоловйов І.А. - 5 балів \nРобота була виконана: 18.10.2021", L"Інформація про першу лабораторну роботу", MB_OK);
			break;
		case 40015:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 5 балів \nКоль Е.В. - 3.7 балів \nСоловйов І.А. - 4.5 балів \nРобота була виконана: 15.11.2021", L"Інформація про другу лабораторну роботу", MB_OK);
			break;
		case 40017:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 5 балів \nКоль Е.В. - 4 балів \nСоловйов І.А. - 4.5 балів \nРобота була виконана: 6.12.2021", L"Інформація про третю лабораторну роботу", MB_OK);
			break;
		case 40019:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 4.5 балів \nКоль Е.В. - 4 балів \nСоловйов І.А. - 4 балів \nРобота була виконана: 20.12.2021", L"Інформація про четверту лабораторну роботу", MB_OK);
			break;
		case 40021:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 85 балів \nКоль Е.В. - Н/Д балів \nСоловйов І.А. - 85 балів \nРобота була виконана: 10.05.2022", L"Інформація про п'яту лабораторну роботу", MB_OK);
			break;
		case 40023:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 90 балів \nКоль Е.В. - Н/Д балів \nСоловйов І.А. - 89 балів \nРобота була виконана: 14.06.2022", L"Інформація про шосту лабораторну роботу", MB_OK);
			break;
		case 40025:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - Н/Д балів \nКоль Е.В. - Н/Д балів \nСоловйов І.А. - Н/Д балів \nРобота була виконана: 28.06.2022", L"Інформація про сьому лабораторну роботу", MB_OK);
			break;
		case 40027:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 90 балів \nКоль Е.В. - Н/Д балів \nСоловйов І.А. - 85 балів \nРобота була виконана: 14.06.2022", L"Інформація про восьму лабораторну роботу", MB_OK);
			break;
		case 40029:
			MessageBox(NULL, L"Виконали цю роботу: \nГончар Д.Г. - 90 балів \nКоль Е.В. - Н/Д балів \nСоловйов І.А. - 85 балів \nРобота була виконана: 14.06.2022", L"Інформація про дев'яту лабораторну роботу", MB_OK);
			break;

		case ID_Lb_1:
			CreateProcess(TEXT("..\\Lb\\Lb_1.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_2:
			CreateProcess(TEXT("..\\Lb\\Lb_2.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_3:
			CreateProcess(TEXT("..\\Lb\\Lb_3.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_4:
			CreateProcess(TEXT("..\\Lb\\Lb_4.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_5:
			CreateProcess(TEXT("..\\Lb\\Lb_5.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_6:
			CreateProcess(TEXT("..\\Lb\\Lb_6.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_7:
			CreateProcess(TEXT("..\\Lb\\Lb_7.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_8:
			CreateProcess(TEXT("..\\Lb\\Lb_8.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Lb_9:
			CreateProcess(TEXT("..\\Lb\\Lb_9.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Clock:
			CreateProcess(TEXT("..\\Lb\\Clock.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
			break;

		case ID_Authors:
			MessageBox(NULL, L"Автори: \nГончар Дмитро Григорович \nКоль Єлізавета Вікторівна \nСоловйов Іван Андрійович \n", L"Інформація про розробників", MB_OK);
			break;
		}
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


