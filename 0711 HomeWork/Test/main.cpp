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
	// struct ����Ȩ��˵������Ĭ���� public
	// class ����Ȩ��˵������Ĭ���� private
	int a;
	int b;
	void Print()
	{
		cout << a << " " << b << endl;
	}
};

int main()
{
	// auto a = 4.0f;	// auto �ڱ���ʱ�ͱ������ȷ������
	S1 s1;
	s1.a = 4;
	s1.b = 5;
	S2 s2;
	s2.a = 3;
	s2.b = 4;
	s2.Print();
	return EXIT_SUCCESS;
}
