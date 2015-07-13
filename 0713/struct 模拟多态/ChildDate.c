#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "ChildDate.h"

void CInit(struct CChildDate *p, int year, int month, int day)
{
	// ���´���û��д obj = �����ķ�ʽ��ֵ
	((struct CMyDate*)p)->pInit = PInit;
	((struct CMyDate*)p)->pInit(p, year, month, day);
	p->m_bIsLeapYear = (p->obj.m_nYear % 4 == 0 && p->obj.m_nYear % 100 != 0) || (p->obj.m_nYear % 400 == 0);
	printf("Call CChildDate Constructor!\n");
}

void CDestroy(struct CChildDate *p)
{
	printf("Call CChildDate Destructor!\n");
	PDestroy(p);
}

int CJudge(struct CChildDate* p)
{
	p->m_bIsLeapYear = (p->obj.m_nYear % 4 == 0 && p->obj.m_nYear % 100 != 0) || (p->obj.m_nYear % 400 == 0);
	return p->m_bIsLeapYear;
}

void InitChild(struct CChildDate* p)
{
	typedef int(*pFuc)(struct CMyDate*);
	// ��ʼ���麯����
	p->vptr = (pFuc*)malloc(sizeof(pFuc) * 2);
	p->vptr[0] = PInit;
	p->vptr[1] = CInit;
	p->pInit = p->vptr[1];
	p->pDestroy = DestroyChild;
	p->pJudge = CJudge;
}

// ����������
void DestroyChild(struct CChildDate* p)
{
	free(p->vptr);
	CDestroy(p);
}
