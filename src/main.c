#include <windows.h>

const wchar_t CLASS_NAME[] = L"Win32HelloWorld";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:	// WM_CLOSE
		{
			PostQuitMessage(0);
			return 0;
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
	// Create class
	WNDCLASS wc = { 0 };
	wc.lpszClassName = CLASS_NAME;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInst;
	RegisterClass(&wc);

	// Create Window
	HWND hwnd = CreateWindow(CLASS_NAME, CLASS_NAME, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 300, 300, 0, 0, hInst, 0);
	if (hwnd == NULL)
	{
		return 0;
	}
	ShowWindow(hwnd, showCmd);

	// Process loop
	MSG msg = { 0 };
	BOOL running = TRUE;
	while (running)
	{
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				running = FALSE;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}