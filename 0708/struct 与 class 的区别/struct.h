#pragma once		// ��ͷ�ļ�ֻ������һ��

typedef struct S1
{
	int a;
	int b;
	int(*pFunc)(int, int);
}S1;

int Add(int, int);
int Sub(int, int);
void Init();
