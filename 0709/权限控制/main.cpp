#include <iostream>
#include "Child.h"

using namespace std;

int main()
{
	CParent p(100);
	CChild c(200);
	// ˽�����Բ������������
	// cout << p.m_nMoney;
	// cout << CParent::s_eStatus;
	p.CostMoney(50);	// public
	c.CostMoney(100);	// ����� public ��Ϊ�����Ա�����̳У����� public ��Ϊ�� public ��ʽ�̳У������ⲿ����ֱ�ӵ��� c.CostMoney(100)
	// c.m_nRestMoney;	// protected ����ֻ��������ڲ����ʣ��ⲿ�����Է���
	return EXIT_SUCCESS;
}
