#pragma once

#include "Parent.h"

class CChild2 :
	protected CParent
{
private:
	int m_nVal;
public:
	CChild2(int x, int y, int year, int month, int day);
	~CChild2();
	void Visit() const;
};

