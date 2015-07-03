#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// C 语言里面的 const 关键字并非真正的常量，他是一个“伪常量”
	const int length = 5;
	// int arr[length]; 伪常量不能用来声明数组长度
	// length = 3; 伪常量不可以直接修改，换言之 const 是一个编译器提示符，提示声明的变量只读
	int *p = &length;
	*p = 3;
	printf("length = %d\n", length);
// 	__asm mov length, 3
// 	printf("length = %d\n", length);
	return 0;
}
