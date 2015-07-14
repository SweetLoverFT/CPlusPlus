#include <iostream>
#include "GrandChild1.h"

using namespace std;

CGrandChild1::CGrandChild1(int x, int y, int year, int month, int day)
	: CChild1(x, y, year, month, day)
{
	cout << "Call CGrandChild1 Constructor!\n";
}

CGrandChild1::~CGrandChild1()
{
	cout << "Call CGrandChild1 Destructor!\n";
}

void CGrandChild1::Visit() const
{
	// ShowPos();	// 不能调用
}
