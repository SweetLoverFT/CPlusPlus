#include <iostream>
#include "Value.h"

using namespace std;

CValue::CValue(int val)
	: m_pnNum(new int)		// 分配了一块堆上的内存，给了一个指针的属性
{
	*m_pnNum = val;
	cout << "Call constructor!\n";
}

CValue::CValue(const CValue& obj)
{
	// m_pnNum = obj.m_pnNum; 浅拷贝构造函数，就是这样赋值的，只传递
	// m_pnNum = new int(*obj.m_pnNum);	// 复合写法
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
