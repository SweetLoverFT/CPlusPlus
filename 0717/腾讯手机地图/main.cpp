#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define MAX_NUM 10
#define PI 3.14159265358979323846
using namespace std;

int n;

struct SArea
{
	unsigned r;
	short alpha;
	short beta;
	short delta;
}s[MAX_NUM];

int Compare(const void *ptr1, const void *ptr2)
{
	const SArea *p1 = static_cast<const SArea*>(ptr1), *p2 = static_cast<const SArea*>(ptr2);
	return p1->r <= p2->r;
}

void Init()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%u%hd%hd", &s[i].r, &s[i].alpha, &s[i].beta);
	qsort(s, n, sizeof(SArea), Compare);
}

double Work()
{
	int i, j, delta;
	double sum = 0.0;
	for (i = 0; i < n; i++)
	{
		s[i].delta = s[i].beta - s[i].alpha;
		for (j = i - 1; j >= 0; j--)
		{
			// Òþ»¼´úÂë
			if (s[i].alpha < s[j].alpha && s[i].beta > s[j].beta)
				s[i].delta = s[j].alpha - s[i].alpha + s[i].beta - s[j].beta;
			else if (s[i].alpha < s[j].alpha && s[i].beta > s[j].alpha)
				s[i].beta = s[j].alpha;
			else if (s[i].alpha < s[j].beta && s[i].beta > s[j].beta)
				s[i].alpha = s[j].beta;
		}
		sum = sum + s[i].r * s[i].r * PI * (s[i].beta - s[i].alpha) / 360.0;
	}
	return sum;
}

int main()
{
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		Init();
		printf("%.3lf\n", Work());
	}
	return 0;
}
