#include <iostream>
#include "Child2.h"

using namespace std;

CChild2::CChild2(int x, int y, int year, int month, int day)
	: CParent(x, y, year, month, day)
	, m_nVal(x)
{
	cout << "Call CChild2 Constructor!\n";
}


CChild2::~CChild2()
{
	cout << "Call CChild2 Destructor!\n";
}

void CChild2::Visit() const
{
	cout << m_nVal << endl;		// ��Ա�����ڣ�ֻ�ܷ��ʱ����˽�г�Ա
	// cout << CParent::m_nX;	// ��Ա���������ܷ����������˽�г�Ա�������м̳е�ѪԵ��ϵ
	cout << m_nYear << endl;	// ����� protected ��Ա���κμ̳з�ʽ�������Ա���һ�����ӷ���
	ShowPos();
	cout << endl;
}
