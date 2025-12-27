export module window;
import <Windows.h>;
import std;

/*
* 命名空间名：	window
* 作用：		包含了对于窗口的处理的函数
* 修改时间：	20251225
* 修改内容：	实现ifDarkTheme
*/
export namespace window
{
	bool createWindow(HINSTANCE& hIns);
	bool ifDarkTheme();
	void onWMSettingchange(HWND hwnd, LPARAM lparam);
}

/*
* 函数名：		ifDarkTheme
* 修改时间：	20251225
* 修改内容：	实现个性化处理
*/
bool window::ifDarkTheme()
{
	DWORD value = 1;
	DWORD size = sizeof(value);

	if (RegGetValue(
		HKEY_CURRENT_USER,
		L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
		L"SystemUsesLightTheme",
		RRF_RT_REG_DWORD,
		nullptr,
		&value,
		&size
	) == ERROR_SUCCESS)
	{
		return value == 0;	// 0 = 暗色模式
	}

	return true;	// 默认是暗色模式，这是一个用于安全的代码
}

void window::onWMSettingchange(HWND hwnd,LPARAM lparam)
{
	if (lparam && wcscmp(reinterpret_cast<LPCWSTR>(lparam), L"ImmersiveColorSet") == 0)
	{
		// 获取旧画刷
		HBRUSH oldBrush = reinterpret_cast<HBRUSH>(
			GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND)
			);

		bool dark = ifDarkTheme();

		// 改变背景颜色
		HBRUSH hBrush = CreateSolidBrush(dark ? RGB(32, 32, 32) : RGB(255, 255, 255));
		SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, reinterpret_cast<LONG_PTR>(hBrush));

		// 释放旧画刷
		if (oldBrush)
			DeleteObject(oldBrush);

		// 触发窗口重绘
		InvalidateRect(hwnd, nullptr, TRUE);
	}
}