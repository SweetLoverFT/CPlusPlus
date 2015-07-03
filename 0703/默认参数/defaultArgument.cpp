#include <string>
#include <iostream>
using namespace std;

void Print()
{
	cout << "Hello, world!\n";
}

// 如果函数有默认参数，那么尽可能不要重载这样的函数，否则会有语义二义性的危险
// 对于有默认参数的函数，我们尽可能提供一个参数最多的函数作为统一的接口就行了
void Print(string s = "SweetLover")
{
	cout << s << endl;
}

int main()
{
	Print();	// 语义二义性
	return EXIT_SUCCESS;
}
