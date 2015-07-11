#pragma once

#include "Parent.h"

class CChild :
	public CParent
{
public:
	CChild(int nMoney = 0);
	~CChild();
	void ShowRestMoney();
};

