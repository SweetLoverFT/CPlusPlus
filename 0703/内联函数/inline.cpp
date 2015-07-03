#include <iostream>
using namespace std;

#define CALC(a, b) a + b

inline int Add(int c, int d)
{
	return c + d;
}

inline int Calc(int a, int b)
{
	return a + b;
}

int main()
{
	int a, b, res;
	cin >> a >> b;
	res = Add(a, b);	// res = c + d;
	cout << res << endl;
	cout << CALC(3, 4) * CALC(1, 2) << endl;	// 3 + 4 * 1 + 2
	cout << Calc(3, 4) * Calc(1, 2) << endl;	// (3 + 4) * (1 + 2)
	return EXIT_SUCCESS;
}
