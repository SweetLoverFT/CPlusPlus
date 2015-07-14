#pragma once

#include "Parent.h"

class CChild1 :
	private CParent
{
private:
	int m_nVal;
public:
	CChild1(int x, int y, int year, int month, int day);
	~CChild1();
	void Visit() const;
};

