#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum EType
{
	CALC_ADD,
	CALC_SUB
};

typedef struct S
{
	int a;
	int b;
	int (*pCalc)(int, int);
}S;

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

void ConstructFactory(S *pS, int type)		// 构造工厂
{
	// 龙生九子，子子不同
	switch (type)
	{
	case CALC_ADD:
		pS->pCalc = Add;
		break;
	case CALC_SUB:
		pS->pCalc = Sub;
		break;
	}
}

int main()
{
	S s1, s2;
	int choice;
	s2.a = s1.a = 7, s2.b = s1.b = 8;
	scanf("%d", &choice);
	ConstructFactory(&s1, choice);
	scanf("%d", &choice);
	ConstructFactory(&s2, choice);
	printf("s1 运算结果为：%d\n", s1.pCalc(s1.a, s1.b));
	printf("s2 运算结果为：%d\n", s2.pCalc(s2.a, s2.b));
	return 0;
}
