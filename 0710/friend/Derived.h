#pragma once

#include "MyVec2.h"

class CDerived :
	public CMyVec2
{
public:
	CDerived();
	~CDerived();
	void Print(const CMyPoint& obj);
};

