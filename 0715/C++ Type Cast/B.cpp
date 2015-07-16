#include <iostream>
#include "B.h"

using namespace std;

B::B()
	: m_nB(0)
{
	cout << "Call B Constructor!\n";
}

B::~B()
{
	cout << "Call B Destructor!\n";
}
