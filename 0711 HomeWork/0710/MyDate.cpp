#include <iostream>
#include "MyDate.h"

using namespace std;

CMyDate::CMyDate(int year /* = 1 */, int month /* = 1 */, int day /* = 1 */)
	: m_nYear(year)
	, m_nMonth(month)
	, m_nDay(day)
{
}

CMyDate::~CMyDate()
{
}

CMyDate& CMyDate::operator +=(int day)
{
	int ret;
	const int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	ret = month[m_nMonth - 1] - m_nDay + 1;
	if (m_nMonth == 2 && (m_nYear % 4 == 0 && m_nYear % 100 != 0 || m_nYear % 400 == 0))
		ret += 1;
	if (day - ret < 0)
	{
		m_nDay += day;
		return *this;
	}
	day -= ret;
	m_nDay = 1;
	m_nMonth = ++m_nMonth % 12;
	if (!m_nMonth)
		m_nMonth = 12;
	else if (m_nMonth == 1)
		m_nYear++;
	while (day >= 0)
	{
		ret = month[m_nMonth - 1];
		if (m_nMonth == 2 && (m_nYear % 4 == 0 && m_nYear % 100 != 0 || m_nYear % 400 == 0))
			ret += 1;
		if (day - ret <= 0)
		{
			m_nDay += day;
			return *this;
		}
		day -= ret;
		m_nMonth = ++m_nMonth % 12;
		if (!m_nMonth)
			m_nMonth = 12;
		else if (m_nMonth == 1)
			m_nYear++;
	}
}

void CMyDate::Print()
{
	cout << m_nYear << "-" << m_nMonth << "-" << m_nDay << endl;
}
