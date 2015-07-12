#include <iostream>
using namespace std;

extern "C"
{
	struct S2
	{
		int a;
		int b;
		void Print()
		{
			cout << a << " " << b << endl;
		}
	};
}

struct S1 
{
	// struct 不加权限说明符，默认是 public
	// class 不加权限说明符，默认是 private
	int a;
	int b;
	void Print()
	{
		cout << a << " " << b << endl;
	}
};

int main()
{
	// auto a = 4.0f;	// auto 在编译时就必须可以确定类型
	S1 s1;
	s1.a = 4;
	s1.b = 5;
	S2 s2;
	s2.a = 3;
	s2.b = 4;
	s2.Print();
	return EXIT_SUCCESS;
}
