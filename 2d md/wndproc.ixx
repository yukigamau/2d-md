export module wndproc;
import <Windows.h>;

import window;

using window::onWMSettingchange;

export LRESULT wndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);

LRESULT wndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_SETTINGCHANGE:
		onWMSettingchange(hwnd, lparam);
		break;

	default:
		return DefWindowProc(hwnd, umsg, wparam, lparam);
		break;
	}

	return 0;
}