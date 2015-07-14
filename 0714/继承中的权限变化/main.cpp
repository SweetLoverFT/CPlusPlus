#include <iostream>
#include "GrandChild1.h"
#include "GrandChild2.h"
#include "GrandChild3.h"
using namespace std;

int main()
{
	// 父类 private 类型的成员，子类任何一种继承方式均会继承失败
	// 导致无法在子类的成员函数内部，访问父类的 private 属性
	CChild1 child1(3, 4, 5, 6, 7);
	CChild2 child2(1, 2, 8, 9, 10);
	CChild3 child3(11, 12, 13, 14, 15);

	// 私有的都不能访问，单类的控制访问权限
	// child1.m_nVal;
	// child2.m_nVal;
	// child3.m_nVal;

	// 外部不可直接访问 private 和 protected
	// child1.m_nYear;		// private 继承，会导致父类传来的任何东西被子类独占，孙子不能享用
	// child1.ShowPos();	// private 继承，会把父类传来的 protected 以及 public 都变更为 protected
	// child2.m_nYear;		// protected 继承，会导致父类传来的任何东西被子类当做传家之宝
	// child2.ShowPos();	// protected 继承，会把父类传来的 protected 以及 public 都变更为 protected
	// child3.m_nYear;		// public 继承，不改变原有属性的控制访问权限
	child3.ShowPos();

	CGrandChild1 gc1(3, 4, 5, 6, 7);
	CGrandChild2 gc2(1, 2, 8, 9, 10);
	CGrandChild3 gc3(11, 12, 13, 14, 15);

	// gc1.ShowPos();		// 不能调用
	// gc2.ShowPos();		// 不能调用
	gc3.ShowPos();			// 可以调用
	return EXIT_SUCCESS;
}
