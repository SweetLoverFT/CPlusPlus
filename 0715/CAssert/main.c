#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>		// C 断言头文件，实际上断言就是 C 的异常处理

int main()
{
	char *p = "Hello, China!";
	assert(strlen(p) > 20);		// 运行时断言，只抛出异常，不去处理
	return 0;
}
