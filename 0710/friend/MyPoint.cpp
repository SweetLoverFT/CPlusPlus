#include <iostream>
#include "MyPoint.h"

using namespace std;

CMyPoint::CMyPoint(int x /* = 0 */, int y /* = 0 */)
	: m_nX(x)
	, m_nY(y)
{
}

CMyPoint::~CMyPoint()
{
}

// 友元作为非本类的访问者，不需要加类作用域去声明的
void Print(const CMyPoint& obj)
{
	// m_nX 是私有的，按理说不允许外部直接访问
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}

void CMyPoint::Print()
{
	// 成员函数都隐藏了 this 指针
	cout << "(" << this->m_nX << ", " << m_nY << ")\n";
}

void CMyPoint::Print(const CMyVec2& obj)
{
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}

void CMyPoint::Print(const CMyPoint& obj)
{
	// 样子上像类外访问，但实际上不是的
	// 所有的对象是不是都属于这个类，生产出来的
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}
