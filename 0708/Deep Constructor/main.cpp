#include <iostream>
#include "Value.h"
using namespace std;

void Test()
{
	// ���¿���������ڽ���ʱ�����쳣
	CValue v1(3);		// �����ʱ�򣬴�����һ���ڴ�
	CValue v2(v1);		// ǳ������ֻ���ݵ�ֵַ�����������ڴ渱��
	cout << v2.GetValue() << endl;
}

int main()
{
	Test();
	return EXIT_SUCCESS;
}
