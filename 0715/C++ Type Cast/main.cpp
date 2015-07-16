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
	// ���� static_cast
	C c;
	float a1 = 5.0;
	auto a2 = static_cast<int>(a1);
	cout << a2 << endl;
	auto a3 = reinterpret_cast<int*>(&a1);
	cout << *a3 << endl;
	printf("%d\n", a1);
	// static_cast<Value>(a2);	// static_cast ǿ��ת������ù��캯��
	auto pDb = reinterpret_cast<double*>(5);
	cout << pDb << endl;
	cout << reinterpret_cast<int>(pDb) << endl;
	// reinterpret_cast ת��ֻ�Ƕ��ڴ��ֽ������½���
	cout << &c << endl;
	cout << reinterpret_cast<B*>(&c) << endl;
	cout << static_cast<B*>(&c) << endl;	// static_cast ����ù��캯��������ָ��ת���л��Զ�ƥ���Ӧ�������ڵ��ڴ��ַ

	// Up-Cast ����ת����ȡ���ڴ���������һС�飬static_cast �ͺ� dynamic_cast
	auto d = dynamic_cast<B*>(&c);
	auto e = static_cast<B*>(&c);

	D x;
	// ת����Ҫ���캯��
	// auto f = dynamic_cast<B*>(&a);
	// auto g = static_cast<B*>(&a);
	// Down-Cast ����ת����С�ڴ����ŵ����ڴ��������
	// auto f = dynamic_cast<E*>(&x);	// dynamic_cast �̳�����������֮���ת�������������麯��������
	auto f = static_cast<E*>(&x);

	const int data = 5;
	auto p = const_cast<int *>(&data);	// const_cast ���������/ɾ�� const��volatile ����
	*p = 10;
	cout << data << endl;
	return EXIT_SUCCESS;
}
