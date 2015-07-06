#include <iostream>
using namespace std;

int Add(int a, int b)
{
	return a + b;
}

void Print()
{
	cout << "Hello, world!\n";
}

int main()
{
	Print();

	// Lambda 表达式的一般形式为：
	// [capture](param)modifier->return type{body}
	// [ 捕获列表 ]( 传入参数列表 ) 修饰符 -> 返回值类型 { 函数体 };
	// int Add(int a, int b){return a + b;}
	// <返回值> 函数名(传入参数列表) 修饰符 {函数体}
	[]()
	{
		cout << "Hello, world!\n";
	}();			// () 是函数调用运算符

	auto p1 = []() -> void
	{
		cout << "Hello, world!\n";
		cout << __FUNCTION__ << endl;
	};
	cout << typeid(p1).name() << endl;
	p1();			// () 是函数调用运算符

	auto p2 = [](int a, int b) -> int { return a + b; };
	cout << p2(3, 4) << endl;

	int a, b;
	cin >> a >> b;
	cout << [](int a, int b)->int
	{
		a = 3, b = 4;
		return a + b;
	}(a, b) << endl;
	cout << a << " " << b << endl;

	{
		int a, b;
		cin >> a >> b;
	}

	// 部或符号捕获的是和这个 Lambda 表达式同名字空间里面的那个变量
	// [capture] 采用的是值传递方式捕获变量，因此 Lambda 表倒是内部的 a 和 b 是副本
	// 副本修改不会影响原本
	// 当捕获列表非空的时候，修饰符 const、mutable，throw 等关键字就可以使用
	// 这些修饰符是和[捕获列表]，捕获列表为空不能修改修饰符
	cout << [a, b]()mutable->int
	{
		a = 3, b = 4;
		return a + b;
	}() << endl;
	cout << a << " " << b << endl;

	// 捕获列表采用引用的方式捕获
	cout << [&a, &b]()->int
	{
		a = 3, b = 4;
		return a + b;
	}() << endl;
	cout << a << " " << b << endl;

	int c, d, e, f;
	cin >> c >> d >> e >> f;

	// 变量定义过多，采用一个个变量值传递方式捕获会导致捕获列表过长！
	// [a, b, c, d, e, f]
	cout << [a, b, c, d, e, f]()->int
	{
		return a + b + c + d + e + f;
	}() << endl;

	// 捕获列表中 = 的作用，把可见域内部的所有变量，都采用值传递的方式引用
	cout << [=]()->int
	{
		return a + b + c + d + e + f;
	}() << endl;

	// 捕获列表中 & 的作用，把可见域内的所有变量，都引用进来
	cout << [&]()->int
	{
		return a + b + c + d + e + f;
	}() << endl;

	// 混合捕获
	[&a, b](){};		// 对于 a，用引用的方式捕获，对于 b，用值传递的方式捕获
	[&, a](){};			// 对于 a，使用值传递方式捕获，对于可见域中其他的对象，一律采用引用的方式捕获
	[=, &b](){};		// 对于 b，使用引用方式捕获，对于可见域中其他的对象，一律采用值传递的方式捕获

	return EXIT_SUCCESS;
}
