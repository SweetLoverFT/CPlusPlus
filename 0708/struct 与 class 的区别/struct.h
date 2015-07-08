#pragma once		// 该头文件只被编译一次

typedef struct S1
{
	int a;
	int b;
	int(*pFunc)(int, int);
}S1;

int Add(int, int);
int Sub(int, int);
void Init();
