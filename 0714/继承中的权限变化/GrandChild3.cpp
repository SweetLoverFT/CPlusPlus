#include <iostream>
#include "GrandChild3.h"

using namespace std;

CGrandChild3::CGrandChild3(int x, int y, int year, int month, int day)
	: CChild3(x, y, year, month, day)
{
	cout << "Call CGrandChild3 Constructor!\n";
}

CGrandChild3::~CGrandChild3()
{
	cout << "Call CGrandChild3 Destructor!\n";
}

void CGrandChild3::Visit() const
{
	ShowPos();	// 可以调用
	cout << endl;
}
