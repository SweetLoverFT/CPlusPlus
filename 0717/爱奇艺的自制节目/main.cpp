#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <climits>
using namespace std;

int Ew, Ex, Ey, Ez, w, x, y, z;

void Work()
{
	int A, B, C, D, i, j, delta, tmp, min1, min2, min = INT_MAX;
	scanf("%d%d%d%d%d%d%d%d", &Ew, &Ex, &Ey, &Ez, &w, &x, &y, &z);
	A = Ew * w;
	B = Ex * x;
	delta = A - B;
	if (delta < 0)
		delta = -delta;

	for (i = 0; i <= y; i++)
	{
		for (j = 0; j <= z; j++)
		{
			C = Ey * i + Ez * j;
			D = Ey * (y - i) + Ez * (z - j);
			tmp = abs(abs(C - D) - delta);
			if (tmp < min)
			{
				min = tmp;
				min1 = C;
				min2 = D;
			}
		}
	}
	C = min1;
	D = min2;
	min1 = A + C - B - D;
	min2 = A + D - B - C;
	if (abs(min1) < abs(min2))
		min = (A + D > B + C ? A + D : B + C);
	else
		min = (A + C > B + D ? A + C : B + D);
	printf("%d\n", min);
}

int main()
{
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
		Work();
	return 0;
}
