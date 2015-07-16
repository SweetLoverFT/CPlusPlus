#include <iostream>
#include "C.h"

using namespace std;

C::C()
	: A()
	, B()
{
	cout << "Call C Constructor!\n";
}

C::~C()
{
	cout << "Call C Destructor!\n";
}
