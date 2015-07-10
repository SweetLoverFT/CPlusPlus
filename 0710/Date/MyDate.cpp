#include <ostream>
#include <sstream>
#include <iostream>
#include "MyDate.h"

using namespace std;

/*
CMyDate::CMyDate()
/ *
	// 如果去掉这里的初始化列表，那么就和编译器默认提供的无参构造函数相同
	// 编译器默认的构造函数，函数体为空
	: m_nYear(0)
	, m_nMonth(0)
	, m_nDay(0)
* /
{
	cout << "Call default construct function!\n";
}
*/

// 如果构造函数参数列表全部都用了默认参数，那么就不要再提供无参数列表的构造函数了，
// 否则会导致定义变量时，编译器的二义性
CMyDate::CMyDate(int year /* = 0 */, int month /* = 0 */, int day /* = 0 */)
	// 初始化列表
	: m_nYear(year)
	, m_nMonth(month)
	, m_nDay(day)
{
	cout << "Call CMyDate(int year, int month, int day)\n";
}

/*
CMyDate::CMyDate(int year / * = 0 * /, int month / * = 0 * /, int day / * = 0 * /)
{
	m_nYear = year;
	m_nMonth = month;
	m_nDay = day;
	cout << "Call CMyDate(int year, int month, int day)\n";
}
*/

/*
CMyDate::CMyDate()
{

}
*/

CMyDate& CMyDate::operator = (const CMyDate& obj)
{
	this->m_nYear = obj.m_nYear;
	this->m_nMonth = obj.m_nMonth;
	this->m_nDay = obj.m_nDay;
	cout << "Call operator = \n";
	return *this;
}

CMyDate::CMyDate(const CMyDate& obj)
{
	m_nYear = obj.m_nYear;
	m_nMonth = obj.m_nMonth;
	m_nDay = obj.m_nDay;
	cout << "Call copy constructor!\n";
}

// 析构函数是唯一的，而且函数名前面有个 ~
CMyDate::~CMyDate()
{
	cout << "Call default destructor!\n";
}

/*
CMyDate::~CMyDate()
{

}
*/

// 快速写代码技巧：
// 1.把声明直接拷贝过来，末尾去掉分号；
// 2.花括号展开，为编写函数体准备
// 3.作为类的成员函数，把所属的作用域给他加上
// 4.如果，生命的函数前，有 static、inline、virtual 这些字样，那么拷贝过来之后要记得删除
void CMyDate::SetYear(int year)
{
	m_nYear = year;
}

void CMyDate::SetMonth(int month)
{
	m_nMonth = month;
}

void CMyDate::SetDay(int day)
{
	m_nDay = day;
}

int CMyDate::GetYear() const
{
	return m_nYear;
}

int CMyDate::GetMonth() const
{
	return m_nMonth;
}

int CMyDate::GetDay() const
{
	return m_nDay;
}

int CMyDate::FromThatDay() const
{
	// 算的是 m_nYear 年 3 月 1 日距离公元元年 3 月 1 日共几天？
	int day = (m_nYear - 1) * 365 + m_nYear / 4 - m_nYear / 100 + m_nYear / 400;
	// 月份表从三月开始，到来年 2 月算作 1 年
	const int month[] = { 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28 };
	if (m_nMonth >= 3)
	{
		int i;
		for (i = 0; i < m_nMonth - 3; i++)
			day += month[i];
		day += m_nDay;
	}
	else
	{
		int isLeapYear = 0;
		// 鼠目寸光，循序逼近
		if (m_nYear % 4 == 0)
			isLeapYear = 1;
		if (m_nYear % 100 == 0)
			isLeapYear = 0;
		if (m_nYear % 400 == 0)
			isLeapYear = 1;
		// isLeapYear = m_nYear % 4 ? 0 : (m_nYear % 100 ? 1 : (m_nYear % 400 ? 0 : 1));
		day -= 31 + 28 + isLeapYear;
		if (m_nMonth == 2)
			day += 31;
		day += m_nDay;
	}

	return day;
}

int CMyDate::FromThatDay(const CMyDate& obj) const
{
	return FromThatDay() - obj.FromThatDay();
}

int CMyDate::FromThatDay(int year, int month, int day) const
{
	CMyDate date(year, month, day);
	return FromThatDay() - date.FromThatDay();
}

int CMyDate::FromThatDay(const CMyDate& obj1, const CMyDate& obj2)
{
	return obj1.FromThatDay() - obj2.FromThatDay();
}

int CMyDate::FromThatDay(int year1, int month1, int day1, int year2, int month2, int day2)
{
	CMyDate date1(year1, month1, day1), date2(year2, month2, day2);
	return date1.FromThatDay() - date2.FromThatDay();
}

int CMyDate::operator -(const CMyDate& obj) const
{
	return FromThatDay() - obj.FromThatDay();
}


/*
int CMyDate::operator -(const CMyDate& obj1, const CMyDate& obj2)
{
	return obj1.FromThatDay() - obj2.FromThatDay();
}
*/

/*
int operator -(const CMyDate& obj1, const CMyDate& obj2)
{
	return obj1.FromThatDay() - obj2.FromThatDay();
}
*/

CMyDate& CMyDate::operator +=(int day)
{
	int tmp;
	const int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	tmp = month[m_nMonth - 1] - m_nDay + 1;
	if (day - tmp < 0)
	{
		m_nDay += day;
		return *this;
	}
	while (day - tmp >= 0)
	{
		day -= tmp;
		m_nMonth = (m_nMonth + 1) % 12;
		if (m_nMonth == 0)
			m_nMonth = 12;
		tmp = month[m_nMonth - 1];
	}
	m_nDay = 1;
	if (day - tmp < 0)
		m_nDay += day;
	return *this;
}

CMyDate::operator int()
{
	return FromThatDay();
}

ostream& operator <<(ostream& out, const CMyDate& obj)
{
	// 字符串流
	ostringstream tmp;
	tmp << obj.m_nYear << "-" << obj.m_nMonth << "-" << obj.m_nDay;
	out << tmp.str();
	return out;
}
