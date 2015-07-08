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
