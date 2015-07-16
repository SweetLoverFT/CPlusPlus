#include <iostream>
using namespace std;

int main()
{
	// static_assert(sizeof(int) == 5, "Right");
	int a = 5;
	try
	{
		a++;
		if (a == 6)
			throw "Error";
	}
	catch (char *s)
	{
		cout << s;
	}
	return 0;
}
