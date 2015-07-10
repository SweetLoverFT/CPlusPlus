#include <iostream>
#include "MyVec2.h"

using namespace std;

CMyVec2::CMyVec2(int x /* = 0 */, int y /* = 0 */)
	: m_nX(x)
	, m_nY(y)
{
}

CMyVec2::~CMyVec2()
{
}

void CMyVec2::Print(const CMyPoint& obj)
{
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}
