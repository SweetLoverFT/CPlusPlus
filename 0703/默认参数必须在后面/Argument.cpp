#include <string>
#include <iostream>
using namespace std;

// Ĭ�ϲ���֮���Ա����ں��棬����Ϊѹե��Ҫ֪��ѹե�Ĵ��򣬴���ʱˮ��ΪĬ�ϲ������Ƿ���Ĭ�ϲ���
int Add(int a, int b, int c = 3)
{
	return a + b + c;
}

int main()
{
	Add(5, 4);	// 
	return EXIT_SUCCESS;
}
