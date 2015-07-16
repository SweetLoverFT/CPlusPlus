#pragma once

#include <tchar.h>
#include <memory.h>
#include <Windows.h>
#include "resource.h"
#define WIN32_LEAN_AND_MEAN	// 从 Windows 库中排除掉极少用的库

struct MSG_ENTRY
{
	UINT nMessage;
	LRESULT(CALLBACK *pfn)(HWND, UINT, WPARAM, LPARAM);
};

#define BEGIN_MESSAGE_MAP() \
	struct MSG_ENTRY list[] = {

#define END_MESSAGE_MAP() \
	};

#define ON_WM_FUNC(__MESSAGE__, __FUNC__) \
	__MESSAGE__, __FUNC__,

ATOM MyRegisterClass(HINSTANCE hInst);											// 窗口类设计与注册
int InitInstance(HINSTANCE hInst, int nCmdShow);								// 实例化
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// 窗口过程函数
void CALLBACK TimerProc(HWND hWnd, UINT msg, UINT_PTR idEvent, DWORD dwTime);	// 时间过程函数

LRESULT CALLBACK OnCreate(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// 创建时调用的函数
LRESULT CALLBACK OnDestroy(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// 销毁时调用的函数
LRESULT CALLBACK OnPaint(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// 窗口重绘时调用的函数
LRESULT CALLBACK OnLBtnDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// 双击窗口时的响应
