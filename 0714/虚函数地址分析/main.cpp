#include <iostream>
using namespace std;

class Base1_1
{
public:
	int base1_1;
	int base1_2;
};

class Base1_2
{
public:
	int base1_1;
	int base1_2;

	void foo(){}
};

class Base1_3
{
public:
	int base1_1;
	int base1_2;

	virtual void base1_fun1() {}
};

class Base1_4
{
public:
	int base1_1;
	int base1_2;

	virtual void base1_fun1() {}
	virtual void base1_fun2() {}
};

class Derive1 : public Base1_4
{
public:
	int derive1_1;
	int derive1_2;
};

class Derive2 : public Base1_4
{
public:
	int derive1_1;
	int derive1_2;

	// ¸²¸Ç»ùÀàº¯Êı
	virtual void base1_fun1() {}
};

int main()
{
	Base1_3 b3;
	Base1_4 b4;
	cout << sizeof(Base1_1) << endl;
	cout << offsetof(Base1_1, base1_1) << endl;
	cout << offsetof(Base1_1, base1_2) << endl << endl;
	cout << sizeof(Base1_2) << endl;
	cout << offsetof(Base1_2, base1_1) << endl;
	cout << offsetof(Base1_2, base1_2) << endl << endl;
	cout << sizeof(Base1_3) << endl;
	cout << offsetof(Base1_3, base1_1) << endl;
	cout << offsetof(Base1_3, base1_2) << endl << endl;
	cout << sizeof(Base1_4) << endl;
	cout << offsetof(Base1_4, base1_1) << endl;
	cout << offsetof(Base1_4, base1_2) << endl << endl;

	Derive1 d1;
	Derive2 d2;
	cout << sizeof(Derive1) << endl;
	cout << offsetof(Derive1, derive1_1) << endl;
	cout << offsetof(Derive1, derive1_2) << endl << endl;
	cout << sizeof(Derive2) << endl;
	cout << offsetof(Derive2, derive1_1) << endl;
	cout << offsetof(Derive2, derive1_2) << endl << endl;
	return EXIT_SUCCESS;

	// cout << is_convertible<A, B>::value
}
