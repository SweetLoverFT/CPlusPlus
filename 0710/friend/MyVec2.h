#pragma once

#include "MyPoint.h"

class CMyVec2
{
	// ��Ԫ�ǵ������������̳еĻ������׵����Ѳ����Ϊ�������
	friend class CMyPoint;
private:
	int m_nX;
	int m_nY;
public:
	CMyVec2(int x = 0, int y = 0);
	~CMyVec2();
	void Print(const CMyPoint& obj);
};

