#include <string>
#include <iostream>
using namespace std;

// 默认参数之所以必须在后面，是因为压榨需要知道压榨的次序，传参时水作为默认参数，是否有默认参数
int Add(int a, int b, int c = 3)
{
	return a + b + c;
}

int main()
{
	Add(5, 4);	// 
	return EXIT_SUCCESS;
}
