#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	const char *s = "Hello, world!";
	printf("%s %d", __FILE__, __LINE__);
	assert(s == "I love you");
	// 0xFF 0xFF 0xFF 0xF0
	// char *pBuf =  ”∆µ÷° ”∆µª∫≥Âƒ⁄»›
	// if (pBuf[index++] == 0xFF && pBuf[index++] == 0xFF && pBuf[index++] == 0xFF && pBuf[index] == 0xF0)index++;

	return 0;
}
