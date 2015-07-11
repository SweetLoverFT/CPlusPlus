#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "SGoods.h"

enum EStatus
{
	STATUS_USED = 1,
	STATUS_KEEP
};

int main()
{
	char sBrand[MAX_SIZE];
	SGoods **ppGoods;
	int i, n, nPrice, nUsed;
	scanf("%d", &n);
	ppGoods = (SGoods **)malloc(sizeof(SGoods *) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%s", &nPrice, sBrand);
		ppGoods[i] = (SGoods *)malloc(sizeof(SGoods));
		// 构造函数过程
		ppGoods[i]->pInit = Init;
		ppGoods[i]->pDestroy = Destroy;
		ppGoods[i]->pSetBrand = SetBrand;
		ppGoods[i]->pSetPrice = SetPrice;
		ppGoods[i]->pInit(ppGoods[i], nPrice, sBrand);

		scanf("%d", &nUsed);
		if (nUsed == STATUS_USED)
		{
			ppGoods[i]->pDestroy(ppGoods[i]);
			free(ppGoods[i]);
			ppGoods[i] = NULL;
		}
	}
	// 类的函数，我们直接用“类名::函数名”
	printf("Total produced %d products,  products are in using!\n", GetTotalGoods(), GetTotalUsedGoods());
	for (i = 0; i < n; i++)
	{
		ppGoods[i]->pDestroy(ppGoods[i]);
		free(ppGoods[i]);
		ppGoods[i] = NULL;
	}

	printf("%d\n", sizeof(SGoods));
	printf("Total produced %d products, %d products are in using!\n", GetTotalGoods(), GetTotalUsedGoods());
	return 0;
}
