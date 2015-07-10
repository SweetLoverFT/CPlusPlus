#pragma once

#include "MyVec2.h"

class CMyPoint
{
	// 友元只是声明，它虽然在代码上看来，是声明于类的内部
	// 但是实际情况是：它并不被这个类包含，Print 根本不是这个函数的成员函数
	friend void Print(const CMyPoint& obj);
	friend class CTest;
	friend class CMyVec2;
private:
	int m_nX;
	int m_nY;
public:
	CMyPoint(int x = 0, int y = 0);
	~CMyPoint();
	void Print();
	void Print(const CMyVec2& obj);
	static void Print(const CMyPoint& obj);
};

