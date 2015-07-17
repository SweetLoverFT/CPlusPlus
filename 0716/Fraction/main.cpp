#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	CFraction f1, f2, f3;
	cin >> f1 >> f2 >> f3;
	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	try
	{
		cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	}
	catch (const char *ex)
	{
		cout << ex << endl;
	}

	cout << "(" << f3 << " + 4)" << " / 3.0 = " << (f3 + 4) / 3.0 << endl;
	return EXIT_SUCCESS;
}
