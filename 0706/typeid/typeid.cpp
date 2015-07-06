#include <iostream>
using namespace std;

class A
{
private:
	int m_nVal;		// ��Ա���� member
public:
	A(int val)		// ���캯��
	{
		m_nVal = val;
	}
	~A()			// ��������
	{

	}
};

class B
{
private:
	double m_fVal;
public:
	B(double val)
	{
		m_fVal = val;
	}
	~B()
	{

	}
	int Add(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	auto a = A(4);
	auto b = B(5.0);
	auto p = &B::Add;
	// typeid ����ʱ����ʶ��
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(p).name() << endl;

	// typeid ����ʱ����ʶ��
	char c = 'A';
	cout << sizeof((c + 1) % 4 + 1.3) << endl;
	cout << typeid((c + 1) % 4 + 1.3).name() << endl;
	return EXIT_SUCCESS;
}
