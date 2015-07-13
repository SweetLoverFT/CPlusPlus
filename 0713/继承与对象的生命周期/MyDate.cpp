#include <iostream>
#include "MyDate.h"

using namespace std;

CMyDate::CMyDate(int year, int month, int day)
	: m_nYear(year)
	, m_nMonth(month)
	, m_nDay(day)
{
	cout << "Call CMyDate Constructor!\n";
}

CMyDate::~CMyDate()
{
	cout << "Call CMyDate Destructor!\n";
}
