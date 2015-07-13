#include <iostream>
#include "Child.h"

using namespace std;

CChild::CChild(CParent *p, int x /* = 0 */, int y /* = 0 */)
	: m_pParent(p)
	, m_nX(x)
	, m_nY(y)
{
	// ���ǳ�Ա�������õ�������ʽ
	// m_nX = this->CParent::GetX() + x;
	// m_nX = m_pParent->GetX() + x;
	// m_nY = m_pParent->GetY() + y;
	// m_nX, m_nY �������Ϊƫ������������ӵĺ���
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
