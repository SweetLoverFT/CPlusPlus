#include <iostream>
#include "Value.h"

using namespace std;

int main()
{
	// int �����ϲ����Ը�ֵ���Զ������ͣ�
	// ������Ϊ���������캯���Լ�������������е���ʽת����
	// ���յ����ˣ��Ǹ�����Ҳ������������ķ�ʽ������
	CValue v = 5.3;
	cout << v.GetValue() << endl;
	return EXIT_SUCCESS;
}
