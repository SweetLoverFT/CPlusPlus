#include <iostream>
#include "Child.h"
#include "ChildDate.h"

using namespace std;

void Work1()
{
	CChildDate date(2015, 7, 13);
}

void Work2()
{
	CParent bg1(320, 480), bg2(160, 200);
	CChild layer(&bg1, 20, 30);
	bg1.ShowPos();
	bg2.ShowPos();
	layer.ShowPos();
	// »Ø³Ç
	layer.SetParent(&bg2);
	layer.ShowPos();
}

int main()
{
	Work1();
	Work2();
	return EXIT_SUCCESS;
}
