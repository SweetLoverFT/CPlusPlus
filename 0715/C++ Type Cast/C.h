#pragma once

#include "A.h"
#include "B.h"

class C :
	public A, public B
{
public:
	C();
	~C();
};

