#include "Parent.h"

CParent::EStatus CParent::s_eStatus = STATUS_KEEP;

CParent::CParent(int nMoney/* = 0*/)
	: m_nMoney(nMoney)
{
}

CParent::~CParent()
{
}

void CParent::CostMoney(int nMoney/* = 0*/)
{
	m_nMoney -= nMoney;
}
