#include <iostream>
#include "MyDate.h"

using namespace std;

int main()
{
	// CMyDate date();		// 调用的是编译器默认提供的
	CMyDate date1(2015, 7, 8);
	date1.SetYear(2014);
	date1.SetMonth(11);
	date1.SetDay(15);
	cout << "This Date is: " << date1.GetYear() << " year, "
		<< date1.GetMonth() << " month, " << date1.GetDay() << " day\n";

	// CMyDate(const CMyDate&)	拷贝构造，默认采用值传递，浅拷贝
	// CMyDate(int year, int month, int day)	自己定义的普通的构造函数
	CMyDate *p = new CMyDate(2013, 4, 27);
	// C++ 里面 new 开辟内存会自动触发类型转换，也就是调用构造函数
	// malloc 只分配内存，不调用构造函数，还需要强制转换
	// 强制转换可能会调用编译器提供的默认转换构造函数，默认转换构造函数是不作为的
	delete p;	// C++ 里面的 delete 不仅仅有 free 的释放内存的功能，调用析构函数

	// 赋值构造函数，实际上是对 = 运算符的重载，此外还是一个值传递，不是地址/引用传递
	// CMyDate date2 = date1;	// 如果变量刚定义就采用赋值构造，那么编译器会把赋值构造优化成编译器的默认构造
	CMyDate date2;
	date2 = date1;
	date2.SetYear(2012);
	date2.SetMonth(12);
	date2.SetDay(22);
	cout << "This date1 is: " << date1.GetYear() << " year, "
		<< date1.GetMonth() << " month, " << date1.GetDay() << " day\n";
	cout << "This date2 is: " << date2.GetYear() << " year, "
		<< date2.GetMonth() << " month, " << date2.GetDay() << " day\n";

	CMyDate date3(date1);	// 拷贝构造
	CMyDate date4 = date1;	// 形式上是赋值构造，但因为创建对象就立刻初始化，所以编译器优化为拷贝构造
	return EXIT_SUCCESS;
}
