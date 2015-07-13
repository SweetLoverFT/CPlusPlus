#include <iostream>
#include "Parent.h"

using namespace std;

CParent::CParent(int x /* = 0 */, int y /* = 0 */)
	: m_nX(x)
	, m_nY(y)
{
	cout << "Call CParent Constructor!\n";
}

CParent::~CParent()
{
}

void CParent::SetPos(int x, int y)
{
	m_nX = x;
	m_nY = y;
}

void CParent::ShowPos() const
{
	cout << "(" << m_nX << ", " << m_nY << ")\n";
}
