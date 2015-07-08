#include "Value.h"

CValue::CValue(int val)
	: m_nVal(val)
{
}

CValue::~CValue()
{
}

void CValue::SetVal(int value)
{
	m_nVal = value;
}

int CValue::GetValue() const
{
	return m_nVal;
}
