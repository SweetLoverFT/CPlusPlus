#include <iostream>
using namespace std;

int num = 3;

// 非匿名命名空间声明方法：namespace 名字空间标识符
// 名字空间可以防止变量作用域的隐藏掩盖
namespace NS1
{
	int num = 5;
	int cnt = 0;
	// 匿名的名字空间
	namespace
	{
		int num = 7;
	}
}

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << ::num << endl;	// :: 作用与运算符，:: 前面什么都没有，则表示默认的全局域 DoMain
	cout << NS1::num << endl;
	// cout << cnt;			// 输出 cnt 需要前缀
	// cout << NS1::<unnamed>::num << endl; 无法打印匿名的名字空间
	using namespace NS1;	// using namespace 省略前缀，开发不提倡
	// cout << num; 二义性这里的 num 和全局的 num 重复了，名字空间的污染问题
	cout << cnt << endl;
	std::cout << "NameSpace\n";

	// typedef 声明函数指针的方式
	// 1.抄写函数声明头部，末尾补充分号 ;
	// 2.对函数名用小括号包围起来，并在函数名前面加上 *
	// 3.改写名称
	typedef int (*pFunc)(int, int);
	pFunc p = Add;	// 声明并定义一个指向 int Add(int a, int b) 的函数指针
	cout << p(3, 4) << endl;

	// using
	// 1.写出 using 函数指针类型名 = 抄写函数声明头部，末尾补充分号 ;
	// 2.挖去函数名，改为 (*)
	using pFun = int (*)(int, int);
	pFun pF = Add;
	cout << pF(7, 8) << endl;
	return EXIT_SUCCESS;
}
