#include <iostream>
#include "Child.h"

using namespace std;

CChild::CChild(CParent *p, int x /* = 0 */, int y /* = 0 */)
	: m_pParent(p)
	, m_nX(x)
	, m_nY(y)
{
	// 这是成员函数调用的完整形式
	// m_nX = this->CParent::GetX() + x;
	// m_nX = m_pParent->GetX() + x;
	// m_nY = m_pParent->GetY() + y;
	// m_nX, m_nY 如果设置为偏移量，将会更加的合理
	cout << "Call CChild Constructor!\n";
}

CChild::~CChild()
{
}

void CChild::SetParent(CParent *p)
{
	m_pParent = p;
}

void CChild::SetPos(int x, int y)
{
	m_nX = x;
	m_nY = y;
}

void CChild::ShowPos() const
{
	cout << "(" << m_pParent->GetX() + m_nX << ", " << m_pParent->GetY() + m_nY << ")\n";
}
