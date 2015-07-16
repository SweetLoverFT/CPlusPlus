#include "StdAfx.h"

HINSTANCE g_hInst;
LPCTSTR g_lpszClassName = L"SweetLover Test Demo";
LPCTSTR g_lpszTittleName = L"";

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

BEGIN_MESSAGE_MAP()
	ON_WM_FUNC(WM_CREATE, OnCreate)
	ON_WM_FUNC(WM_DESTROY, OnDestroy)
	ON_WM_FUNC(WM_PAINT, OnPaint)
	ON_WM_FUNC(WM_LBUTTONDOWN, OnLBtnDown)
END_MESSAGE_MAP()

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int i;
	// 观察者设计模式
	for (i = 0; i < sizeof(list) / sizeof(list[0]); i++)
	{
		if (msg == list[i].nMessage)
		{
			list[i].pfn(hWnd, msg, wParam, lParam);
			break;
		}
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

LRESULT CALLBACK OnCreate(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	MessageBeep(MB_ICONINFORMATION);
	MessageBox(NULL, L"窗口创建了！", L"WM_CREATE", MB_OK | MB_ICONINFORMATION);
	SetTimer(hWnd, IDE_TIMER, 10, TimerProc);
	return EXIT_SUCCESS;
}

LRESULT CALLBACK OnDestroy(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(EXIT_SUCCESS);	// 发送 WM_QUIT
	return EXIT_SUCCESS;
}

LRESULT CALLBACK OnPaint(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	RECT rect;
	BITMAP bmp;
	HBITMAP hBmp;
	PAINTSTRUCT ps;
	HGDIOBJ hGdiObj;
	HDC hDC, hDCMem;
	static int x = 0, y = 0;
	static BOOL bDtX = TRUE, bDtY = TRUE;

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

	return EXIT_SUCCESS;
}

LRESULT CALLBACK OnLBtnDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int nResp;
	MessageBeep(MB_ICONQUESTION);
	nResp = MessageBox(NULL, L"你按下了鼠标左键，对不对？", L"测谎仪", MB_YESNOCANCEL | MB_ICONQUESTION);
	switch (nResp)
	{
	case IDYES:
		MessageBeep(MB_ICONINFORMATION);
		MessageBox(NULL, L"你是一个诚实的孩子！", L"测谎结果", MB_OK | MB_ICONINFORMATION);
		break;
	case IDNO:
		MessageBeep(MB_ICONERROR);
		MessageBox(NULL, L"你是一个不诚实的孩子！", L"测谎结果", MB_OK | MB_ICONERROR);
		break;
	case IDCANCEL:
	default:
		MessageBeep(MB_ICONWARNING);
		MessageBox(NULL, L"你不敢正面回答我的问题！", L"测谎结果", MB_OK | MB_ICONWARNING);
	}

	return EXIT_SUCCESS;
}
