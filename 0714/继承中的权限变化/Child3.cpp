#include <iostream>
#include "Child3.h"

using namespace std;

CChild3::CChild3(int x, int y, int year, int month, int day)
	: CParent(x, y, year, month, day)
	, m_nVal(x)
{
	cout << "Call CChild3 Constructor!\n";
}


CChild3::~CChild3()
{
	cout << "Call CChild3 Destructor!\n";
}

void CChild3::Visit() const
{
	cout << m_nVal << endl;		// ��Ա�����ڣ�ֻ�ܷ��ʱ����˽�г�Ա
	// cout << CParent::m_nX;	// ��Ա���������ܷ����������˽�г�Ա�������м̳е�ѪԵ��ϵ
	cout << m_nYear << endl;	// ����� protected ��Ա���κμ̳з�ʽ�������Ա���һ�����ӷ���
	ShowPos();
	cout << endl;
}
