#include <iostream>
#include "Value.h"
using namespace std;

void Test()
{
	// 以下拷贝构造会在结束时触发异常
	CValue v1(3);		// 构造的时候，创建了一块内存
	CValue v2(v1);		// 浅拷贝，只传递地址值，但不创建内存副本
	cout << v2.GetValue() << endl;
}

int main()
{
	Test();
	return EXIT_SUCCESS;
}
