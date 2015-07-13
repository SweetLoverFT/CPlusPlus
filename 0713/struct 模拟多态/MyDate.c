#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MyDate.h"

void PInit(struct CMyDate* p, int year, int month, int day)
{
	p->m_nYear = year;
	p->m_nMonth = month;
	p->m_nDay = day;
	printf("Call CMyDate Constructor!\n");
}

void PDestroy(struct CMyDate* p)
{
	printf("Call CMyDate Destructor!\n");
}

void InitParent(struct CMyDate* p)
{
	p->pInit = PInit;
	p->pDestroy = PDestroy;
	p->pJudge = NULL;
}
