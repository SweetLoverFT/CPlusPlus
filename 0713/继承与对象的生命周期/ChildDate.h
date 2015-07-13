#pragma once

#include "MyDate.h"

class CChildDate :
	public CMyDate
{
private:
	bool m_bIsLeapYear;
public:
	CChildDate(int year, int month, int day);
	~CChildDate();
};

