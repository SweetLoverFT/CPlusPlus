#pragma once

#include "MyPoint.h"

class CMyVec2
{
	// 友元是第三方，如果你继承的话，父亲的朋友不会成为你的朋友
	friend class CMyPoint;
private:
	int m_nX;
	int m_nY;
public:
	CMyVec2(int x = 0, int y = 0);
	~CMyVec2();
	void Print(const CMyPoint& obj);
};

