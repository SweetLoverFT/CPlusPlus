#include <ostream>
#include <sstream>
#include <iostream>
#include "MyDate.h"

using namespace std;

/*
CMyDate::CMyDate()
/ *
	// ���ȥ������ĳ�ʼ���б���ô�ͺͱ�����Ĭ���ṩ���޲ι��캯����ͬ
	// ������Ĭ�ϵĹ��캯����������Ϊ��
	: m_nYear(0)
	, m_nMonth(0)
	, m_nDay(0)
* /
{
	cout << "Call default construct function!\n";
}
*/

// ������캯�������б�ȫ��������Ĭ�ϲ�������ô�Ͳ�Ҫ���ṩ�޲����б�Ĺ��캯���ˣ�
// ����ᵼ�¶������ʱ���������Ķ�����
CMyDate::CMyDate(int year /* = 0 */, int month /* = 0 */, int day /* = 0 */)
	// ��ʼ���б�
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

// ����������Ψһ�ģ����Һ�����ǰ���и� ~
CMyDate::~CMyDate()
{
	cout << "Call default destructor!\n";
}

/*
CMyDate::~CMyDate()
{

}
*/

// ����д���뼼�ɣ�
// 1.������ֱ�ӿ���������ĩβȥ���ֺţ�
// 2.������չ����Ϊ��д������׼��
// 3.��Ϊ��ĳ�Ա���������������������������
// 4.����������ĺ���ǰ���� static��inline��virtual ��Щ��������ô��������֮��Ҫ�ǵ�ɾ��
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
	// ����� m_nYear �� 3 �� 1 �վ��빫ԪԪ�� 3 �� 1 �չ����죿
	int day = (m_nYear - 1) * 365 + m_nYear / 4 - m_nYear / 100 + m_nYear / 400;
	// �·ݱ�����¿�ʼ�������� 2 ������ 1 ��
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
		// ��Ŀ��⣬ѭ��ƽ�
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
	// �ַ�����
	ostringstream tmp;
	tmp << obj.m_nYear << "-" << obj.m_nMonth << "-" << obj.m_nDay;
	out << tmp.str();
	return out;
}
