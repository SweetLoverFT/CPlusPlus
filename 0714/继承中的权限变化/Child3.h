#pragma once

#include "Parent.h"

class CChild3 :
	public CParent
{
private:
	int m_nVal;
public:
	CChild3(int x, int y, int year, int month, int day);
	~CChild3();
	void Visit() const;
};

