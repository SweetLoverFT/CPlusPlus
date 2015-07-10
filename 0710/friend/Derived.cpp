#include <iostream>
#include "Derived.h"

using namespace std;

CDerived::CDerived()
{
}

CDerived::~CDerived()
{
}

void CDerived::Print(const CMyPoint& obj)
{
	// cout << obj.m_nX;	// 不允许，朋友无法继承
}
