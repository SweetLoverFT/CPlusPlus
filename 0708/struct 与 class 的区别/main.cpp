extern "C"
{
	#include "struct.h"
}
#include <iostream>
using namespace std;

// struct 与 class 在 C++ 中的区别是：struct 默认是 public 访问权限
// class 默认是 private 访问权限
// struct 可以按照 C 语言的方式在 C++ 中编译
struct S2
{
// private:
	int a;
	int b;
	// 属性和行为被真正的绑定到一起后，就不需要传递参数了
	int Add()
	{
		return a + b;
	}
};

extern "C"
{
	// 旧式的 (pdf) 接口，主要作用是完成 C++ 对 C 接口调用的兼容
	typedef struct Point
	{
		int x;
		int y;
	}Point;
}

int main()
{
	S2 s2;
	Point pt;	// Point 声明的 pt 一定是 C 语言版本的
	Init();
	cin >> s2.a >> s2.b;
	cout << s2.Add() << endl;
	return EXIT_SUCCESS;
}
