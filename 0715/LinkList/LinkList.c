#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

// 整型的链表
typedef struct SLinkList
{
	int nVal;
	struct SLinkList *pNext;
}SLinkList, *LPSLinkList;

LPSLinkList Init(int n)
{
	int data, i = 1;
	LPSLinkList pHead, pTmp;
	pHead = pTmp = (LPSLinkList)malloc(sizeof(SLinkList));
	scanf("%d", &data);
	pTmp->nVal = data;
	while (i++ < n)
	{
		pTmp->pNext = (LPSLinkList)malloc(sizeof(SLinkList));
		pTmp = pTmp->pNext;
		scanf("%d", &data);
		pTmp->nVal = data;
	}
	pTmp->pNext = NULL;
	return pHead;
}

void ShowList(LPSLinkList pHead)
{
	while (pHead)
	{
		printf("%d ", pHead->nVal);
		pHead = pHead->pNext;
	}
	printf("\n");
}

void FreeList(LPSLinkList pHead)
{
	LPSLinkList pTmp;
	while (pHead)
	{
		pTmp = pHead->pNext;
		free(pHead);
		pHead = pTmp;
	}
}

int main()
{
	int n;
	LPSLinkList pHead;
	scanf("%d", &n);
	pHead = Init(n);
	ShowList(pHead);
	FreeList(pHead);
	return 0;
}
