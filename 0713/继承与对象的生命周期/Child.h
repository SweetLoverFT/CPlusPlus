#pragma once

#include "Parent.h"

class CChild
	: public CParent
{
private:
	int m_nX;			// 应该设计 m_nX 为偏移量，相对参考系的偏移值
	int m_nY;			// m_nY 同理
	CParent *m_pParent;
public:
	CChild(CParent *p, int x = 0, int y = 0);
	~CChild();
	void SetParent(CParent *p);
	virtual void SetPos(int x, int y);
	void ShowPos() const;
	PROPERTY(int, X, m_nX);
	PROPERTY(int, Y, m_nY);
};

