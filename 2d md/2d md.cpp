import <Windows.h>;
import std;
import window;

using window::createWindow;

/*
* 函数名：		main
* fun name:
* 参数：		默认
* param:		default
* 修改时间：	20251223
* modify time:
*/
int CALLBACK WinMain(
	_In_ HINSTANCE hIns,
	_In_opt_ HINSTANCE hPreIns,
	_In_ LPSTR lpCmdLine,
	_In_ int ncmdshow)
{
	createWindow(hIns);

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
