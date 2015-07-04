#include <iostream>
using namespace std;

int main()
{
	int a = 3, b = 7;
	int *pA = &a;
	int *&rpA = pA;	// 引用指针
	int ** const ppA = &pA;
	// 对于 TYPE &r 可以转换为 TYPE * const p;
	// 但是以后出现的 r 都必须用 *p 表示
	*rpA = 5;		// 所有的 rpA 都可以被替换成 *ppA，故这里是 **ppA
	cout << "a = " << a << ", *pA = " << *pA << ", *rpA = " << *rpA << endl;
	cout << "&a = " << static_cast<void*>(&a) << ", &b = " << static_cast<void*>(&b) << ", rpA = " << static_cast<void*>(rpA) << ", pA = " << static_cast<void*>(pA) << endl;
	rpA = &b;
	cout << "&a = " << static_cast<void*>(&a) << ", &b = " << static_cast<void*>(&b) << ", rpA = " << static_cast<void*>(rpA) << ", pA = " << static_cast<void*>(pA) << endl;
	return EXIT_SUCCESS;
}
