#pragma once

#include "MyVec2.h"

class CMyPoint
{
	// ��Ԫֻ������������Ȼ�ڴ����Ͽ�����������������ڲ�
	// ����ʵ������ǣ�������������������Print ����������������ĳ�Ա����
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

