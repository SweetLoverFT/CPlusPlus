// Í³¼Æ table
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int s_nTable[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int main()
{
	FILE *fp = fopen("res.txt", "w");
	int i, j, tmp, sum;
	for (i = 0; i <= 3000; i++)
	{
		tmp = i;
		sum = 0;
		for (j = 0; j < 4; j++)
		{
			sum = sum + s_nTable[tmp % 10];
			tmp = tmp / 10;
		}
		if (i != 3000)
			fprintf(fp, "%d, ", sum);
		else
			fprintf(fp, "%d", sum);
	}
	return 0;
}
