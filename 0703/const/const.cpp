#include <iostream>
using namespace std;

int main()
{
	// C++ 中，const 表示只读修饰符，修饰的不是这个变量名，修饰的对象是地址
	const int LENGTH = 5;
	int arr[LENGTH];
	int *p = const_cast<int*>(&LENGTH);
	*p = 3;
	cout << LENGTH;
	return EXIT_SUCCESS;
}