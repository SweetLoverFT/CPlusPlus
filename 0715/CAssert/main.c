#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>		// C ����ͷ�ļ���ʵ���϶��Ծ��� C ���쳣����

int main()
{
	char *p = "Hello, China!";
	assert(strlen(p) > 20);		// ����ʱ���ԣ�ֻ�׳��쳣����ȥ����
	return 0;
}
