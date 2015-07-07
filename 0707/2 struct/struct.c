#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct A
{
	char a;
	int b;
};

struct B
{
	char a;
	int b;
	short c;
};

struct C
{
	struct A a;		// 聚合
	short c;
};

int main()
{
	// 这个代码给出了结构体对其的重要性
	// 网络流数据必须按照 1 字节对齐，防止接收到的数据按照错误格式解析，含有垃圾字符，节省流量
	struct A st1 = { 'A', 4};
	struct B st2 = { 'B', 6, -7 };
	struct C st3 = { 'T', 4, 0 };
	printf("%hd, %hd, %hd\n", st1, st2, st3);
	printf("%d, %d, %d\n", st1, st2, st3);
	// 挂羊头卖狗肉
	struct A *p1 = &st2, *p2 = &st3;
	// 这里的转换和结构体类型无关，但和结构体内的内存排布有关
	printf("%hd, %hd", ((struct C*)p1)->c, ((struct B*)p2)->c);	// 弱类型，比较自由
	return 0;
}
