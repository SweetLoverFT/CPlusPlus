#include <iostream>
#include "MyDate.h"

using namespace std;

int main()
{
	CMyDate date1(1, 2, 18), date2(1, 7, 8), date3(4, 2, 22), date4(4, 3, 15), date5(100, 1, 17), date6(200, 3, 5), date7(2000, 1, 15), date8(2000, 7, 5), date9(2014, 11, 10), date10(2015, 7, 10);
	cout << date1.FromThatDay() << endl;
	cout << date2.FromThatDay() << endl;
	cout << date3.FromThatDay() << endl;
	cout << date4.FromThatDay() << endl;
	cout << date5.FromThatDay() << endl;
	cout << date6.FromThatDay() << endl;
	cout << date7.FromThatDay() << endl;
	cout << date8.FromThatDay() << endl;
	cout << CMyDate::FromThatDay(date10, date9) << endl;
	cout << date10 - date9 << endl;		// date10.operator-(date9) 运算符显示调用，相当于 date10 - date9

	cout << static_cast<int>(date1) << endl;
	date10 += 100;
	cout << date10 << endl;
	return EXIT_SUCCESS;
}
