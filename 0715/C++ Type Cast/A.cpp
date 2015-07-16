#include <iostream>
#include "A.h"

using namespace std;

A::A()
	: m_nA(0)
{
	cout << "Call A Constructor!\n";
}

A::~A()
{
	cout << "Call A Destructor!\n";
}
