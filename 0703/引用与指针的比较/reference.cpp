#include <iostream>
using namespace std;

struct STest
{
	double &rfData;
};

int main()
{
	// 引用的语法
	// 一经定义就需要立刻初始化，初始化为指向的对象
	// TYPE &r = obj;
	int data = 5, obj = 3;
	int *p = &data, &r = data;
	cout << "*p = " << *p << ", data = " << data << ", obj = " << obj << endl;
	p = &obj;
	cout << "*p = " << *p << ", data = " << data << ", obj = " << obj << endl;
	cout << "r = " << r << ", data = " << data << ", obj = " << obj << endl;
	r = obj;	// 引用就是直接修改内存中的内容，不能修改指向
	cout << "r = " << r << ", data = " << data << ", obj = " << obj << endl;

	// 指针可以修改指向
	p = nullptr;		// C++ 的空指针

	// 本质对比
	// 1.在指针中，const 如果出现在 * 前面，则表示数值不可以更改，但是指针的指向可以更改：const int *pA; int const *pA;
	// 2.在指针中，const 如果出现在 * 后面，则表示数值可以更改，但是指针的指向不可以更改：int * const pA;
	// int &rB = nullptr; 不允许，引用必须指向存在的内存实体！
	// rT 的含义不等同于 pA，因为 rT 相当于 *pA
	int &rT = *((int*)0x30);	// 这个做法不在开发里面用
	int * const pA = nullptr;

	double fData = 3.14;
	double *pfData = &fData, &rfData = fData;
	cout << "sizeof(pfData) = " << sizeof(pfData) << ", sizeof(rfData) = " << sizeof(rfData) << endl;
	cout << "sizeof(*pfData) = " << sizeof(*pfData) << endl;

	// 结构体去证明
	cout << "sizeof(STest) = " << sizeof(STest) << endl;	// C 里面必须是 struct STest
	return 0;
}
