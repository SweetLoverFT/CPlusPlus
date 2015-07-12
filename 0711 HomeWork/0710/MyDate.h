#pragma once
class CMyDate
{
private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
public:
	CMyDate(int year = 1, int month = 1, int day = 1);
	~CMyDate();
	CMyDate& operator +=(int day);
	void Print();
};

