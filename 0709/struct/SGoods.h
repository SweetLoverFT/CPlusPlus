#pragma once

#define MAX_SIZE 32

int nID;
int nUsedNum;

typedef struct SGoods
{
	char sBrand[MAX_SIZE];
	int nPrice;
	// p �������Ǽٶ��� this ָ�룬pInit ָ��ĺ����������Ǽٶ��Ĺ��캯��
	void(*pInit)(struct SGoods *p, int nPrice, const char *sBrand);
	void(*pDestroy)(struct SGoods *p);
	void(*pSetBrand)(struct SGoods *p, const char *sBrand);
	void(*pSetPrice)(struct SGoods *p, int nPrice);
}SGoods;

int GetTotalGoods();		// ��̬����û�� this ָ�룬��˲���ʹ�� const ����
int GetTotalUsedGoods();	// ��ǰʹ�õı�ֵƷ

void Init(SGoods *p, int nPrice, const char *sBrand);
void Destroy(SGoods *p);
void SetBrand(SGoods *p, const char *sBrand);
void SetPrice(SGoods *p, int nPrice);

