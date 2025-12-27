import <Windows.h>;
import sqlite;
import sqlitedefault;
import window;
import wndproc;

using sqlite::Sql;
using sqlitedefault::DATABASE_NAME, sqlitedefault::SKIN_DB_INI;
/*
* 函数名：		createWindow
* 参数：		hIns
* 修改时间：	20251228
* 修改内容：	接入数据库用于自定义界面
*/
bool window::createWindow(HINSTANCE& hIns)
{
	WNDCLASS win{};
	win.hInstance = hIns;
	win.hIcon = NULL;
	win.lpfnWndProc = wndProc;
	win.lpszClassName = L"Main";
	win.style = CS_HREDRAW | CS_VREDRAW;

	Sql s(DATABASE_NAME, SKIN_DB_INI);

	// 根据系统颜色选择颜色
	if (ifDarkTheme())
		win.hbrBackground = CreateSolidBrush(RGB(32, 32, 32));
	else
		win.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));

	RegisterClass(&win);

	HWND main = CreateWindow(
		L"Main",
		L"主页",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr,
		nullptr,
		hIns,
		NULL
	);

	ShowWindow(main, SW_SHOW);

	UpdateWindow(main);

	return true;
}
