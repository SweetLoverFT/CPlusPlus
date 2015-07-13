#include <iostream>
#include "ChildDate.h"

using namespace std;

CChildDate::CChildDate(int year, int month, int day)
	: CMyDate(year, month, day)
{
	// CMyDate::m_nYear ÍêÕûĞ´·¨
	m_bIsLeapYear = (m_nYear % 4 == 0 && m_nYear % 100 != 0) || (m_nYear % 400 == 0);
	cout << "Call CChildDate Constructor!\n";
}

CChildDate::~CChildDate()
{
	cout << "Call CChildDate Destructor!\n";
}
