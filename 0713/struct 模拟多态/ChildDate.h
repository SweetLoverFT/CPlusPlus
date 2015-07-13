#pragma once

#include "MyDate.h"

struct CChildDate
{
	struct CMyDate obj;
	int m_bIsLeapYear;
	int(**vptr)(struct CMyDate*);	// Ðéº¯Êý±í
	void(*pInit)(struct CChildDate *p, int year, int month, int day);
	void(*pDestroy)(struct CChildDate *p);
	int(*pJudge)(struct CChildDate* p);
};

void CInit(struct CChildDate *p, int year, int month, int day);
void CDestroy(struct CChildDate *p);
int CJudge(struct CChildDate* p);

void InitChild(struct CChildDate* p);
void DestroyChild(struct CChildDate* p);
