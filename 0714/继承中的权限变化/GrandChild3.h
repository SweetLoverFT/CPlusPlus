#pragma once

#include "Child3.h"

class CGrandChild3 :
	public CChild3
{
public:
	CGrandChild3(int x, int y, int year, int month, int day);
	~CGrandChild3();
	void Visit() const;
};

