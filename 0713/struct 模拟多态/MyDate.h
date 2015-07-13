#pragma once

struct CMyDate
{
	int m_nYear;
	int m_nMonth;
	int m_nDay;
	// Ðéº¯Êý±í£¬Ê¡ÂÔ
	void(*pInit)(struct CMyDate* p, int year, int month, int day);
	void(*pDestroy)(struct CMyDate* p);
	int(*pJudge)(struct CMyDate* p);
};

void PInit(struct CMyDate* p, int year, int month, int day);
void PDestroy(struct CMyDate* p);

void InitParent(struct CMyDate* p);
