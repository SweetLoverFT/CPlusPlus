#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "struct.h"

enum EType
{
	METHOD_ADD,
	METHOD_SUB
};

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

void Init()
{
	S1 s1;
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case METHOD_ADD:
		s1.pFunc = Add;
		break;
	case METHOD_SUB:
		s1.pFunc = Sub;
		break;
	}
	scanf("%d%d", &s1.a, &s1.b);
	printf("s1.pFun(%d, %d) = %d", s1.a, s1.b, s1.pFunc(s1.a, s1.b));
}
