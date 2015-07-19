#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

class CMyDate
{
private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
	int m_nCnt;
	static const int s_nNum[];
	static const int s_nTable[];
public:
	CMyDate(int val)
		: m_nCnt(0)
	{
		m_nDay = val % 100;
		val = val / 100;
		m_nMonth = val % 100;
		val = val / 100;
		m_nYear = val;
	}
	~CMyDate()
	{

	}
	int GetCount() const
	{
		return m_nCnt;
	}
	int Count()
	{
		int i, nYear = m_nYear, nMonth = m_nMonth, nDay = m_nDay, nSum = 0;
		for (i = 0; i < 4; i++)
		{
			nSum = nSum + s_nNum[nYear % 10];
			nYear = nYear / 10;
		}
		for (i = 0; i < 2; i++)
		{
			nSum = nSum + s_nNum[nMonth % 10];
			nMonth = nMonth / 10;
		}
		for (i = 0; i < 2; i++)
		{
			nSum = nSum + s_nNum[nDay % 10];
			nDay = nDay / 10;
		}
		return nSum;
	}
	int operator ++()
	{
		m_nCnt++;
		int nMonthDay = s_nTable[m_nMonth - 1] + (m_nMonth == 2 && ((m_nYear % 4 == 0 && m_nYear % 100 != 0) || (m_nYear % 400 == 0)) ? 1 : 0);
		if (++m_nDay > nMonthDay)
		{
			m_nDay = 1;
			if (++m_nMonth > 12)
			{
				m_nYear++;
				m_nMonth = 1;
			}
		}
		if (m_nYear == 3000)
			m_nCnt = -1;

		return Count();
	}
};

const int CMyDate::s_nNum[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
const int CMyDate::s_nTable[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	int i, T, val, m;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		int cnt;
		scanf("%d%d", &val, &m);
		CMyDate date(val);
		do 
		{
			cnt = ++date;
		}
		while (cnt != m || cnt != -1);
		printf("%d\n", date.GetCount());
	}
	return 0;
}
