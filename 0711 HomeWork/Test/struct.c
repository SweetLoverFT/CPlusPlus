#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct S3
{
	int a;
	int b;
	// p �൱�� C++ class ����� this ָ��
	void(*pPrint)(struct S3 *p);
};

void Print(struct S3 *p)
{
	printf("a = %d, b = %d\n", p->a, p->b);
}
