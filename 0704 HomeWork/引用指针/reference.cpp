#include <iostream>
using namespace std;

int main()
{
	int a = 3, b = 7;
	int *pA = &a;
	int *&rpA = pA;	// ����ָ��
	int ** const ppA = &pA;
	// ���� TYPE &r ����ת��Ϊ TYPE * const p;
	// �����Ժ���ֵ� r �������� *p ��ʾ
	*rpA = 5;		// ���е� rpA �����Ա��滻�� *ppA���������� **ppA
	cout << "a = " << a << ", *pA = " << *pA << ", *rpA = " << *rpA << endl;
	cout << "&a = " << static_cast<void*>(&a) << ", &b = " << static_cast<void*>(&b) << ", rpA = " << static_cast<void*>(rpA) << ", pA = " << static_cast<void*>(pA) << endl;
	rpA = &b;
	cout << "&a = " << static_cast<void*>(&a) << ", &b = " << static_cast<void*>(&b) << ", rpA = " << static_cast<void*>(rpA) << ", pA = " << static_cast<void*>(pA) << endl;
	return EXIT_SUCCESS;
}
