#include <iostream>
#include "Child.h"

using namespace std;

CChild::CChild(int nMoney /* = 0 */)
	: CParent(nMoney)
{
	m_nRestMoney = nMoney;
}

CChild::~CChild()
{
}

void CChild::ShowRestMoney()
{
	// protected ���ͣ����������������ڲ����ʣ��ⲿ���Է���
	cout << m_nRestMoney;
	// cout << m_nMoney;	// ����� private �����Ա����ۼ̳�
}
