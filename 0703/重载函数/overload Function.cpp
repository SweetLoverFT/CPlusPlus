#include <string>
#include <iostream>
using namespace std;

void Print();
/*
{
	cout << "Hello, world!\n";
}
*/

void Print(string s);
/*
{
	cout << s << endl;
}
*/

void Print(string s, int cnt);
/*
{
	int i;
	for (i = 0; i < cnt; i++)
		cout << s << endl;
}
*/

void Print(int cnt, string s);
/*
{
	int i;
	for (i = 0; i < cnt; i++)
		cout << s << endl;
}
*/

// extern "C" void Test(int a, int b);
// C ���Ա������ı��뷽ʽ�ǣ����ں�����ǰ���һ�� ��_����Ȼ���ٰѺ������ŵ��»��ߺ���ƴ������
// ����֮���ǲ�����������룬������������ 2 ����ͬ��ͬ�����������ǲ���������
// ��Ϊ��������������Ҫ������� _Test
extern "C" void Test();

// ���غ������д���ͬ������ͬ�ĺ�����ǰ����Ҫ����������������������ǵ����Ͳ�������ͬ
int Add(int a, int b)
{
	cout << a << " + " << b << " = " << a + b << endl;
	return a + b;
}

int Add(int b, int a)
{
	return a + b;
}

int main()
{
	// error LNK2019: �޷��������ⲿ���� "void __cdecl Print(void)" (?Print@@YAXXZ)���÷����ں��� _main �б�����
	Print();
	// error LNK2019: �޷��������ⲿ���� "void __cdecl Print(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)" (?Print@@YAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)���÷����ں��� _main �б�����
	Print("I Love you!");
	// error LNK2019: �޷��������ⲿ���� "void __cdecl Print(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)" (?Print@@YAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z)���÷����ں��� _main �б�����
	Print("SweetLover", 3);
	// error LNK2019: �޷��������ⲿ���� "void __cdecl Print(int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)" (?Print@@YAXHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)���÷����ں��� _main �б�����
	Print(3, "SweetLover");
	// C ���Ա����ĺ���
	Test();
	// ֻ�޸���ͬ���͵Ĵ�������ʲô
	Add(3, 4);
	return EXIT_SUCCESS;
}
