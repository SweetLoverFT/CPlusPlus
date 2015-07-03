#include <iostream>
using namespace std;

int num = 3;

// �����������ռ�����������namespace ���ֿռ��ʶ��
// ���ֿռ���Է�ֹ����������������ڸ�
namespace NS1
{
	int num = 5;
	int cnt = 0;
	// ���������ֿռ�
	namespace
	{
		int num = 7;
	}
}

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << ::num << endl;	// :: �������������:: ǰ��ʲô��û�У����ʾĬ�ϵ�ȫ���� DoMain
	cout << NS1::num << endl;
	// cout << cnt;			// ��� cnt ��Ҫǰ׺
	// cout << NS1::<unnamed>::num << endl; �޷���ӡ���������ֿռ�
	using namespace NS1;	// using namespace ʡ��ǰ׺���������ᳫ
	// cout << num; ����������� num ��ȫ�ֵ� num �ظ��ˣ����ֿռ����Ⱦ����
	cout << cnt << endl;
	std::cout << "NameSpace\n";

	// typedef ��������ָ��ķ�ʽ
	// 1.��д��������ͷ����ĩβ����ֺ� ;
	// 2.�Ժ�������С���Ű�Χ���������ں�����ǰ����� *
	// 3.��д����
	typedef int (*pFunc)(int, int);
	pFunc p = Add;	// ����������һ��ָ�� int Add(int a, int b) �ĺ���ָ��
	cout << p(3, 4) << endl;

	// using
	// 1.д�� using ����ָ�������� = ��д��������ͷ����ĩβ����ֺ� ;
	// 2.��ȥ����������Ϊ (*)
	using pFun = int (*)(int, int);
	pFun pF = Add;
	cout << pF(7, 8) << endl;
	return EXIT_SUCCESS;
}
