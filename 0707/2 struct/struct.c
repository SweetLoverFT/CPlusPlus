#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct A
{
	char a;
	int b;
};

struct B
{
	char a;
	int b;
	short c;
};

struct C
{
	struct A a;		// �ۺ�
	short c;
};

int main()
{
	// �����������˽ṹ��������Ҫ��
	// ���������ݱ��밴�� 1 �ֽڶ��룬��ֹ���յ������ݰ��մ����ʽ���������������ַ�����ʡ����
	struct A st1 = { 'A', 4};
	struct B st2 = { 'B', 6, -7 };
	struct C st3 = { 'T', 4, 0 };
	printf("%hd, %hd, %hd\n", st1, st2, st3);
	printf("%d, %d, %d\n", st1, st2, st3);
	// ����ͷ������
	struct A *p1 = &st2, *p2 = &st3;
	// �����ת���ͽṹ�������޹أ����ͽṹ���ڵ��ڴ��Ų��й�
	printf("%hd, %hd", ((struct C*)p1)->c, ((struct B*)p2)->c);	// �����ͣ��Ƚ�����
	return 0;
}
