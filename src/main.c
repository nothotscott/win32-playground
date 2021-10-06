#include <windows.h>
#include "main.h"

const wchar_t CLASS_NAME[] = L"Win32HelloWorld";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CLOSE:
		{
			if (MessageBox(hwnd, L"Do you really want to quit?", L"Confirmation", MB_OKCANCEL) == IDOK)
			{
				DestroyWindow(hwnd);
			}
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		case WM_CTLCOLORSTATIC:
		{

			break;
		}
		default:
		{
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
	}
	return 0;
}

int WINAPI
wWinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PWSTR cmd, int showCmd)
{
	// Debug
	OutputDebugStringA("Hello!\n");
	// Create class
	WNDCLASS wc = { 0 };
	wc.lpszClassName = CLASS_NAME;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInst;
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	RegisterClass(&wc);

	// Create Window
	RECT wr = { 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT };
	AdjustWindowRectEx(&wr, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0);
	SIZE size = { wr.right - wr.left, wr.bottom - wr.top };
	POINT pos = { GetSystemMetrics(SM_CXSCREEN) / 2 - size.cx / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - size.cy / 2 };
	HWND hwnd = CreateWindow(CLASS_NAME, CLASS_NAME, WS_OVERLAPPEDWINDOW | WS_VISIBLE, pos.x, pos.y, size.cx, size.cy, 0, 0, hInst, 0);
	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, showCmd);

	// Process loop
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}