#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "SGoods.h"

int nID = 0;
int nUsedNum = 0;
// int CGoods::s_nID = 0;
// int CGoods::s_nUsedNum = 0;

int GetTotalGoods()
{
	return nID;
}

int GetTotalUsedGoods()
{
	return nUsedNum;
}

// p 就是用来模拟 this，模拟构造函数
void Init(SGoods *p, int nPrice, const char *sBrand)
{
	strcpy(p->sBrand, sBrand);
	p->nPrice = nPrice;
	nID++;
	nUsedNum++;
	printf("Product ID: %d:\n\tBrand = %s\n\tPrice = %d\n", nID, p->sBrand, p->nPrice);
}

void Destroy(SGoods *p)
{
	nUsedNum--;
	printf("Used this product:\n\tBrand = %s\n\tPrice = %d\n", p->sBrand, p->nPrice);
}

void SetBrand(SGoods *p, const char *sBrand)
{
	strcpy(p->sBrand, sBrand);
}

void SetPrice(SGoods *p, int nPrice)
{
	p->nPrice = nPrice;
}
