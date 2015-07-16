#pragma once

#include <tchar.h>
#include <memory.h>
#include <Windows.h>
#include "resource.h"
#define WIN32_LEAN_AND_MEAN	// �� Windows �����ų��������õĿ�

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

ATOM MyRegisterClass(HINSTANCE hInst);											// �����������ע��
int InitInstance(HINSTANCE hInst, int nCmdShow);								// ʵ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// ���ڹ��̺���
void CALLBACK TimerProc(HWND hWnd, UINT msg, UINT_PTR idEvent, DWORD dwTime);	// ʱ����̺���

LRESULT CALLBACK OnCreate(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// ����ʱ���õĺ���
LRESULT CALLBACK OnDestroy(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// ����ʱ���õĺ���
LRESULT CALLBACK OnPaint(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// �����ػ�ʱ���õĺ���
LRESULT CALLBACK OnLBtnDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// ˫������ʱ����Ӧ
