#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// C ��������� const �ؼ��ֲ��������ĳ���������һ����α������
	const int length = 5;
	// int arr[length]; α�������������������鳤��
	// length = 3; α����������ֱ���޸ģ�����֮ const ��һ����������ʾ������ʾ�����ı���ֻ��
	int *p = &length;
	*p = 3;
	printf("length = %d\n", length);
// 	__asm mov length, 3
// 	printf("length = %d\n", length);
	return 0;
}
