#include <iostream>
#include "GrandChild2.h"

using namespace std;

CGrandChild2::CGrandChild2(int x, int y, int year, int month, int day)
	: CChild2(x, y, year, month, day)
{
	cout << "Call CGrandChild2 Constructor!\n";
}

CGrandChild2::~CGrandChild2()
{
	cout << "Call CGrandChild2 Destructor!\n";
}

void CGrandChild2::Visit() const
{
	ShowPos();	// 可以调用
	cout << endl;
}
