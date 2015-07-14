#pragma once

#include "Child2.h"

class CGrandChild2 :
	public CChild2
{
public:
	CGrandChild2(int x, int y, int year, int month, int day);
	~CGrandChild2();
	void Visit() const;
};

