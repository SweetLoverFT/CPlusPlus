#include <iostream>
#include "Value.h"

using namespace std;

CValue::CValue(int val)
	: m_pnNum(new int)		// ������һ����ϵ��ڴ棬����һ��ָ�������
{
	*m_pnNum = val;
	cout << "Call constructor!\n";
}

CValue::CValue(const CValue& obj)
{
	// m_pnNum = obj.m_pnNum; ǳ�������캯��������������ֵ�ģ�ֻ����
	// m_pnNum = new int(*obj.m_pnNum);	// ����д��
	m_pnNum = new int;
	*m_pnNum = *obj.m_pnNum;
	cout << "Call copy constructor!\n";
}

CValue::~CValue()
{
	delete m_pnNum;
	cout << "Call destructor!\n";
}

int CValue::GetValue() const
{
	return *m_pnNum;
}
