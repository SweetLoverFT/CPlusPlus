#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
// 最常见的泛型用法
template <class T>
void Swap(T& obj1, T& obj2)
{
	T tmp = obj1;
	obj1 = obj2;
	obj2 = tmp;
}
*/

// Add 可以加 int、double，还可以加字符串（把两个字符串拼起来）
template <class T>
T Add(T obj1, T obj2)
{
	return obj1 + obj2;
}

// typeid(T) == typeid(char *)
// 模板特化，具体问题具体分析，特殊情况特殊对待
template <>
char* Add(char* obj1, char* obj2)
{
	char *p = new char[strlen(obj1) + strlen(obj2) + 1];
	strcpy(p, obj1);
	strcat(p, obj2);
	return p;
}

int main()
{
/*
	int a = 3, b = 6;
	Swap(a, b);
	cout << a << ", " << b << endl;
*/
	int a = 3, b = 5;
	char s1[] = "Hello", s2[] = " SweetLover";
	auto res = Add(s1, s2);
	cout << res << endl;
	cout << Add(a, b);
	delete[] res;
	return EXIT_SUCCESS;
}