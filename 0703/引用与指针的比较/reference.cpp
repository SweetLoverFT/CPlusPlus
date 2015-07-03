#include <iostream>
using namespace std;

struct STest
{
	double &rfData;
};

int main()
{
	// ���õ��﷨
	// һ���������Ҫ���̳�ʼ������ʼ��Ϊָ��Ķ���
	// TYPE &r = obj;
	int data = 5, obj = 3;
	int *p = &data, &r = data;
	cout << "*p = " << *p << ", data = " << data << ", obj = " << obj << endl;
	p = &obj;
	cout << "*p = " << *p << ", data = " << data << ", obj = " << obj << endl;
	cout << "r = " << r << ", data = " << data << ", obj = " << obj << endl;
	r = obj;	// ���þ���ֱ���޸��ڴ��е����ݣ������޸�ָ��
	cout << "r = " << r << ", data = " << data << ", obj = " << obj << endl;

	// ָ������޸�ָ��
	p = nullptr;		// C++ �Ŀ�ָ��

	// ���ʶԱ�
	// 1.��ָ���У�const ��������� * ǰ�棬���ʾ��ֵ�����Ը��ģ�����ָ���ָ����Ը��ģ�const int *pA; int const *pA;
	// 2.��ָ���У�const ��������� * ���棬���ʾ��ֵ���Ը��ģ�����ָ���ָ�򲻿��Ը��ģ�int * const pA;
	// int &rB = nullptr; ���������ñ���ָ����ڵ��ڴ�ʵ�壡
	// rT �ĺ��岻��ͬ�� pA����Ϊ rT �൱�� *pA
	int &rT = *((int*)0x30);	// ����������ڿ���������
	int * const pA = nullptr;

	double fData = 3.14;
	double *pfData = &fData, &rfData = fData;
	cout << "sizeof(pfData) = " << sizeof(pfData) << ", sizeof(rfData) = " << sizeof(rfData) << endl;
	cout << "sizeof(*pfData) = " << sizeof(*pfData) << endl;

	// �ṹ��ȥ֤��
	cout << "sizeof(STest) = " << sizeof(STest) << endl;	// C ��������� struct STest
	return 0;
}
