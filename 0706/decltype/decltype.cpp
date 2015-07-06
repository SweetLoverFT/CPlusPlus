#include <iostream>
using namespace std;

// 运行时类型推断：在 C++ 14 中，支持最好
double Add(int val1, double val2)
{
	decltype(val1 + val2) sum = val1 + val2;
	return sum;
}

int main()
{
	cout << Add(3, 4.5) << endl;
	return EXIT_SUCCESS;
}
