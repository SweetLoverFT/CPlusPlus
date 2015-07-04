#include <string>
#include <iostream>
using namespace std;

enum EType
{
	TYPE_INT,
	TYPE_DOUBLE,
	TYPE_STRING
};

int Add(int, int);
double Add(double, double);
string Add(string, string);

int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

// string 可以直接相加，是因为已经有了运算符重载
string Add(string a, string b)
{
	return a + b;
}

// C 语言的宏不考虑类型相关性，因此已经有基本的泛型思想在里面
// 宏不支持调试，对象如果是类里面的私有成员，外部不能直接访问，牵涉到权限问题，那么久泡汤了
// 宏不安全
#define ADD(num1, num2) \
	num1 + num2

// #define CALC(a, b) a + b
// 上述宏 CALC(3, 4) * CALC(1, 2) 就是不安全的
// 这里的宏替换，是把这个表达是替换过来，它并不是先算出表达式的数值，再做替换
#define MAX(a, b) ( ( (a) > (b) ) ? (a) : (b) )

int main()
{
	int type;
	cout << "Please input data type(0:INT 1:DOUBLE 2:STRING):";
	cin >> type;
/*
	switch (type)
	{
	case TYPE_INT:
		{
			int a, b;
			cin >> a >> b;
			cout << Add(a, b);
		}
		break;
	case TYPE_DOUBLE:
		{
			double a, b;
			cin >> a >> b;
			cout << Add(a, b);
		}
		break;
	case TYPE_STRING:
		{
			string a, b;
			cin >> a >> b;
			cout << Add(a, b);
		}
		break;
	}
*/
	switch (type)
	{
	case TYPE_INT:
		{
			int a, b;
			cin >> a >> b;
			cout << ADD(a, b);
		}
		break;
	case TYPE_DOUBLE:
		{
			double a, b;
			cin >> a >> b;
			cout << ADD(a, b);
		}
		break;
	case TYPE_STRING:
		{
			string a, b;
			cin >> a >> b;
			cout << ADD(a, b);
		}
		break;
	}

	double a, b;
	cin >> a >> b;
	cout << MAX(a++, b++) << endl;
	return EXIT_SUCCESS;
}
