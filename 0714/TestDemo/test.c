#include <Windows.h>
#include "resource.h"
#define WIN32_LEAN_AND_MEAN	// 从 Windows 库中排除掉极少用的库

HINSTANCE g_hInst;
LPCTSTR g_lpszClassName = L"SweetLover Test Demo";
LPCTSTR g_lpszTittleName = L"";

ATOM MyRegisterClass(HINSTANCE hInst);											// 窗口类设计与注册
int InitInstance(HINSTANCE hInst, int nCmdShow);								// 实例化
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// 窗口过程函数
void CALLBACK TimerProc(HWND hWnd, UINT msg, UINT_PTR idEvent, DWORD dwTime);	// 时间过程函数

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	g_hInst = hInstance;
	MyRegisterClass(hInstance);
	InitInstance(hInstance, nShowCmd);

	// Windows 消息循环，消息泵
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return EXIT_SUCCESS;
}

ATOM MyRegisterClass(HINSTANCE hInst)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = g_lpszClassName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	return RegisterClass(&wc);
}

int InitInstance(HINSTANCE hInst, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(g_lpszClassName, g_lpszTittleName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,
		hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);			// 发送了 WM_PAINT
	return EXIT_SUCCESS;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	RECT rect;
	BITMAP bmp;
	HBITMAP hBmp;
	PAINTSTRUCT ps;
	HGDIOBJ hGdiObj;
	HDC hDC, hDCMem;
	static int x = 0, y = 0;
	static BOOL bDtX = TRUE, bDtY = TRUE;

	// switch 里面编写自定义消息的处理
	switch (msg)
	{
	case WM_CREATE:
		MessageBeep(MB_ICONINFORMATION);
		MessageBox(NULL, L"窗口创建了！", L"WM_CREATE", MB_OK | MB_ICONINFORMATION);
		SetTimer(hWnd, IDE_TIMER, 10, TimerProc);
		break;
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);	// 发送 WM_QUIT
		break;
	case WM_PAINT:
		GetClientRect(hWnd, &rect);
		hDC = BeginPaint(hWnd, &ps);
		hDCMem = CreateCompatibleDC(hDC);
		hBmp = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MIKU));
		GetObject(hBmp, sizeof(BITMAP), &bmp);
		hGdiObj = SelectObject(hDCMem, hBmp);
		BitBlt(hDC, x, y, bmp.bmWidth, bmp.bmHeight, hDCMem, 0, 0, SRCCOPY);
		if ((bDtX && ++x == rect.right - rect.left - bmp.bmWidth) || (!bDtX && --x == 0))
			bDtX = 1 - bDtX;
		if ((bDtY && ++y == rect.bottom - rect.top - bmp.bmHeight) || (!bDtY && --y == 0))
			bDtY = 1 - bDtY;
		// ReleaseDC() 与 GetDC() 相对
		DeleteDC(hDCMem);
		DeleteObject(hGdiObj);
		EndPaint(hWnd, &ps);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void CALLBACK TimerProc(HWND hWnd, UINT msg, UINT_PTR idEvent, DWORD dwTime)
{
	if (idEvent == IDE_TIMER)
	{
		RECT rect;
		GetClientRect(hWnd, &rect);
		InvalidateRect(hWnd, &rect, TRUE);	// 发送 WM_PAINT
	}
}
