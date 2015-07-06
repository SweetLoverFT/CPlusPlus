#include <iostream>
using namespace std;

const int LENGTH = 10;

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	// int(A::*pFun)(int, int) = A::Add;
	// cocos2d::Label *label
	// auto label = cocos2d::Label::create();
	auto pFunc = Add;
	cout << pFunc(3, 4) << endl;

	// auto 功能：
	// 1.简化声明，前提建立在等号/冒号右边类型确定
	// 2.遍历集合里面所有的元素，集合可以是数组，C 语言的一维数组，不存在下标越界
	int arr[LENGTH];
	for (auto& element : arr)		// 如果要修改数值，则需要用 &
		cin >> element;
	for (auto& element : arr)
		cout << element << " ";
	cout << endl;
	return EXIT_SUCCESS;
}
