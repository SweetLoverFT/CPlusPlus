#include <iostream>
#include "Child1.h"

using namespace std;

CChild1::CChild1(int x, int y, int year, int month, int day)
	: CParent(x, y, year, month, day)
	, m_nVal(x)
{
	cout << "Call CChild1 Constructor!\n";
}

CChild1::~CChild1()
{
	cout << "Call CChild1 Destructor!\n";
}

void CChild1::Visit() const
{
	cout << m_nVal << endl;		// 成员函数内，只能访问本类的私有成员
	// cout << CParent::m_nX;	// 成员函数，不能访问其他类的私有成员，即便有继承的血缘关系
	cout << m_nYear << endl;	// 父类的 protected 成员，任何继承方式，都可以被第一代孩子访问
	ShowPos();
	cout << endl;
}
