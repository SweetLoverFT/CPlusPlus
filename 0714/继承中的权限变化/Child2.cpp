#include <iostream>
#include "Child2.h"

using namespace std;

CChild2::CChild2(int x, int y, int year, int month, int day)
	: CParent(x, y, year, month, day)
	, m_nVal(x)
{
	cout << "Call CChild2 Constructor!\n";
}


CChild2::~CChild2()
{
	cout << "Call CChild2 Destructor!\n";
}

void CChild2::Visit() const
{
	cout << m_nVal << endl;		// 成员函数内，只能访问本类的私有成员
	// cout << CParent::m_nX;	// 成员函数，不能访问其他类的私有成员，即便有继承的血缘关系
	cout << m_nYear << endl;	// 父类的 protected 成员，任何继承方式，都可以被第一代孩子访问
	ShowPos();
	cout << endl;
}
