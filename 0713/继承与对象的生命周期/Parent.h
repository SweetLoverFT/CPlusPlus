#pragma once

#include "Macro.h"

// 指的就是游戏里面的背景
class CParent
{
private:
	int m_nX;
	int m_nY;
public:
	CParent(int x = 0, int y = 0);
	~CParent();
	virtual void SetPos(int x, int y);
	void ShowPos() const;
	PROPERTY(int, X, m_nX);
	PROPERTY(int, Y, m_nY);
};

