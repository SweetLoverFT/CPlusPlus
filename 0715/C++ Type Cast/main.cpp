#include <iostream>
#include "C.h"
#include "E.h"
using namespace std;

class Value
{
private:
	int m_nValue;
public:
/*
	Value(int nVal)
		: m_nValue(nVal)
	{
		cout << "Call Value Constructor!\n";
	}
*/
	~Value()
	{
		cout << "Call Value Destructor!\n";
	}
};

int main()
{
	// 数据 static_cast
	C c;
	float a1 = 5.0;
	auto a2 = static_cast<int>(a1);
	cout << a2 << endl;
	auto a3 = reinterpret_cast<int*>(&a1);
	cout << *a3 << endl;
	printf("%d\n", a1);
	// static_cast<Value>(a2);	// static_cast 强制转换会调用构造函数
	auto pDb = reinterpret_cast<double*>(5);
	cout << pDb << endl;
	cout << reinterpret_cast<int>(pDb) << endl;
	// reinterpret_cast 转换只是对内存字节序重新解释
	cout << &c << endl;
	cout << reinterpret_cast<B*>(&c) << endl;
	cout << static_cast<B*>(&c) << endl;	// static_cast 会调用构造函数，并且指针转化中会自动匹配对应类型所在的内存地址

	// Up-Cast 上行转换，取大内存对象里面的一小块，static_cast 就和 dynamic_cast
	auto d = dynamic_cast<B*>(&c);
	auto e = static_cast<B*>(&c);

	D x;
	// 转换需要构造函数
	// auto f = dynamic_cast<B*>(&a);
	// auto g = static_cast<B*>(&a);
	// Down-Cast 下行转换，小内存对象放到大内存对象里面
	// auto f = dynamic_cast<E*>(&x);	// dynamic_cast 继承类与派生类之间的转换，尤其是有虚函数表的情况
	auto f = static_cast<E*>(&x);

	const int data = 5;
	auto p = const_cast<int *>(&data);	// const_cast 是用于添加/删除 const、volatile 属性
	*p = 10;
	cout << data << endl;
	return EXIT_SUCCESS;
}
