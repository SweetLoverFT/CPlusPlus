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
// C 语言编译器的编译方式是：现在函数名前面加一个 “_”，然后再把函数名放到下划线后面拼接起来
// 换言之就是参数不参与编译，尽管你声明了 2 个不同的同名函数，但是不可以重载
// 因为这两个函数都需要被编译成 _Test
extern "C" void Test();

// 重载函数，中次序不同算作不同的函数，前提是要交换次序的两个参数，他们的类型不可以相同
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
	// error LNK2019: 无法解析的外部符号 "void __cdecl Print(void)" (?Print@@YAXXZ)，该符号在函数 _main 中被引用
	Print();
	// error LNK2019: 无法解析的外部符号 "void __cdecl Print(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)" (?Print@@YAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)，该符号在函数 _main 中被引用
	Print("I Love you!");
	// error LNK2019: 无法解析的外部符号 "void __cdecl Print(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int)" (?Print@@YAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z)，该符号在函数 _main 中被引用
	Print("SweetLover", 3);
	// error LNK2019: 无法解析的外部符号 "void __cdecl Print(int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)" (?Print@@YAXHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)，该符号在函数 _main 中被引用
	Print(3, "SweetLover");
	// C 语言编译后的函数
	Test();
	// 只修改相同类型的次序会造成什么
	Add(3, 4);
	return EXIT_SUCCESS;
}
