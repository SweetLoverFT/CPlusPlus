#include <iostream>
#include "Child1.h"

using namespace std;

CChild1::CChild1(int x, int y, int year, int month, int day)
	: CParent(x, y, year, month, day)
	, m_nVal(x)
{
	cout << "Call CChild1 Constructor!\n";
}

CChild1::~CChild1()
{
	cout << "Call CChild1 Destructor!\n";
}

void CChild1::Visit() const
{
	cout << m_nVal << endl;		// ��Ա�����ڣ�ֻ�ܷ��ʱ����˽�г�Ա
	// cout << CParent::m_nX;	// ��Ա���������ܷ����������˽�г�Ա�������м̳е�ѪԵ��ϵ
	cout << m_nYear << endl;	// ����� protected ��Ա���κμ̳з�ʽ�������Ա���һ�����ӷ���
	ShowPos();
	cout << endl;
}
