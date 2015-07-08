#include <iostream>
#include "Value.h"

using namespace std;

int main()
{
	// int 理论上不可以赋值给自定义类型，
	// 但是因为单参数构造函数以及复制运算过程中的隐式转换，
	// 最终导致了，那个变量也被当做对象构造的方式创建了
	CValue v = 5.3;
	cout << v.GetValue() << endl;
	return EXIT_SUCCESS;
}
