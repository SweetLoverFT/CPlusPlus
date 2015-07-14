#include <iostream>
#include "Parent.h"

using namespace std;

// ĞÙÑÀÀûÃüÃû·¨
CParent::CParent(int x, int y, int year, int month, int day)
	: m_nX(x)
	, m_nY(y)
	, m_nYear(year)
	, m_nMonth(month)
	, m_nDay(day)
{
	cout << "Call CParent Constructor!\n";
}

CParent::~CParent()
{
	cout << "Call CParent Destructor!\n";
}

void CParent::ShowPos() const
{
	cout << "(" << m_nX << ", " << m_nY << ")";
}

void CParent::ShowDate() const
{
	cout << m_nYear << "-" << m_nMonth << "-" << m_nDay;
}
