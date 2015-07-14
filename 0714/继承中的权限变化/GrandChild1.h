#pragma once

#include "Child1.h"

class CGrandChild1 :
	public CChild1
{
public:
	CGrandChild1(int x, int y, int year, int month, int day);
	~CGrandChild1();
	void Visit() const;
};

