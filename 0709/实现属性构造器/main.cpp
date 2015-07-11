#include <iostream>
#include "MyDate.h"		// 一般函数
#include "DateMy.h"		// 宏编程实现属性构造器的

using namespace std;

int main()
{
	CMyDate date1(2014, 11, 10);
	CDateMy date2(2015, 7, 9);
	cout << date1.GetYear() << "-" << date1.GetMonth() << "-" << date1.GetDay() << endl;
	date1.SetYear(2015);
	date1.SetMonth(7);
	date1.SetDay(9);
	cout << date2.GetYear() << "-" << date2.GetMonth() << "-" << date2.GetDay() << endl;
	date2.SetYear(2014);
	date2.SetMonth(11);
	date2.SetDay(10);
	return EXIT_SUCCESS;
}
