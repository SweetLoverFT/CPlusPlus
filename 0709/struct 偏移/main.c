#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// �겻������ͣ�����ʵ�� C ���Եķ���
// C ������ṹ��ƫ�Ƶ��漼����
#define OFFSET(__TYPE__, __MEMBER__) \
	(size_t)(&((__TYPE__*)NULL)->__MEMBER__)

typedef struct STest
{
	char a;
	int b;
	short c;
	double d;
	float e;
}STest;

int main()
{
	printf("OFFSET(STest, a) = %d\n", (size_t)(&((STest*)NULL)->a));
	printf("OFFSET(STest, a) = %d\n", OFFSET(STest, a));
	printf("OFFSET(STest, b) = %d\n", OFFSET(STest, b));
	printf("OFFSET(STest, c) = %d\n", OFFSET(STest, c));
	printf("OFFSET(STest, d) = %d\n", OFFSET(STest, d));
	printf("OFFSET(STest, e) = %d\n", OFFSET(STest, e));
	printf("sizeof(STest) = %d\n", sizeof(STest));
	return 0;
}
