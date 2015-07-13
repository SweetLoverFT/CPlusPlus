#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ChildDate.h"

int main()
{
	struct CChildDate date;
	InitChild(&date);
	date.pInit(&date, 2016, 2, 3);
	if (date.pJudge(&date))
		printf("isLeapYear!\n");
	else
		printf("notLeapYear!\n");
	DestroyChild(&date);
	return 0;
}
