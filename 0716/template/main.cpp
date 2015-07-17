#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
// ����ķ����÷�
template <class T>
void Swap(T& obj1, T& obj2)
{
	T tmp = obj1;
	obj1 = obj2;
	obj2 = tmp;
}
*/

// Add ���Լ� int��double�������Լ��ַ������������ַ���ƴ������
template <class T>
T Add(T obj1, T obj2)
{
	return obj1 + obj2;
}

// typeid(T) == typeid(char *)
// ģ���ػ������������������������������Դ�
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