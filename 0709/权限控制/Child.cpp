#include <iostream>
#include "Child.h"

using namespace std;

CChild::CChild(int nMoney /* = 0 */)
	: CParent(nMoney)
{
	m_nRestMoney = nMoney;
}

CChild::~CChild()
{
}

void CChild::ShowRestMoney()
{
	// protected 类型，子类可以在子类的内部访问，外部可以访问
	cout << m_nRestMoney;
	// cout << m_nMoney;	// 父类的 private 不可以被自累继承
}
