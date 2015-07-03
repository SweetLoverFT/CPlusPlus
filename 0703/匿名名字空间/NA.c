#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num = 5;

int main()
{
	int num = 3;
	{
		int num = 7;
		{
			extern num;
			num = 10;
			printf("%d\n", num);
		}
		printf("%d\n", num);
	}
	printf("%d\n", num);
	return 0;
}
