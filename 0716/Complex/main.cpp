#include <iostream>
#include <complex>
#include "Fraction.h"

using namespace std;

int main()
{
	complex<CFraction> c(CFraction(3, 7), CFraction(1, 4));
	cout << c << endl;
}
