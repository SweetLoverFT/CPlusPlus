#pragma once

#define MAX_SIZE 32

int nID;
int nUsedNum;

typedef struct SGoods
{
	char sBrand[MAX_SIZE];
	int nPrice;
	// p 就是我们假定的 this 指针，pInit 指向的函数就是我们假定的构造函数
	void(*pInit)(struct SGoods *p, int nPrice, const char *sBrand);
	void(*pDestroy)(struct SGoods *p);
	void(*pSetBrand)(struct SGoods *p, const char *sBrand);
	void(*pSetPrice)(struct SGoods *p, int nPrice);
}SGoods;

int GetTotalGoods();		// 静态函数没有 this 指针，因此不能使用 const 修饰
int GetTotalUsedGoods();	// 当前使用的保值品

void Init(SGoods *p, int nPrice, const char *sBrand);
void Destroy(SGoods *p);
void SetBrand(SGoods *p, const char *sBrand);
void SetPrice(SGoods *p, int nPrice);

