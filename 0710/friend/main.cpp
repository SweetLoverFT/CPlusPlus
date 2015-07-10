#include "Test.h"

int main()
{
	CMyPoint pt(3, 4);
	CMyVec2 vec2(5, 6);
	CTest t;
	// 证明友元和本类无关，否则应该这么打印
	// CMyPoint::Print(pt)	当 Print 为静态函数时
	// pt.Print();
	Print(pt);				// 友元的输出方式，没有 this，也没有类 CMyPoint:: 作用域
	pt.Print();				// 成员函数的，有 this
	CMyPoint::Print(pt);	// 类的输出方式，也没有 this，但是类作为对象的模板，是不是可以直接访问，内政

	t.Print(pt);			// 友元类的成员函数输出方式
	CTest::OutPut(pt);		// 友元类的类函数输出方式

	// 友元：尽可能杜绝互为朋友的情况，因为它十分严重的破坏了类的封装性
	pt.Print(vec2);
	vec2.Print(pt);
	return 0;
}
