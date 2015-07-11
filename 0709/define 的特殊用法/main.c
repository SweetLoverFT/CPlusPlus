#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TO_STRING(name) #name
#define CONNECT(symbol, num) symbol##num

int main()
{
	int data1 = 3, data2 = 4, data3 = 5;
	printf("data1 = %d\n", CONNECT(data, 1));
	printf(TO_STRING(data2)" = %d\n", CONNECT(data, 2));
	printf(TO_STRING(CONNECT(data, 3))" = %d\n", CONNECT(data, 3));
	return 0;
}
