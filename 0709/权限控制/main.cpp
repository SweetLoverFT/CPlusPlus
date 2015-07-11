#include <iostream>
#include "Child.h"

using namespace std;

int main()
{
	CParent p(100);
	CChild c(200);
	// 私有属性不允许类外访问
	// cout << p.m_nMoney;
	// cout << CParent::s_eStatus;
	p.CostMoney(50);	// public
	c.CostMoney(100);	// 父类的 public 行为，可以被子类继承，并且 public 行为以 public 方式继承，所以外部可以直接调用 c.CostMoney(100)
	// c.m_nRestMoney;	// protected 类型只能子类的内部访问，外部不可以访问
	return EXIT_SUCCESS;
}
