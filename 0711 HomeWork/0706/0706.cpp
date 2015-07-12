#include <iostream>
using namespace std;

int main()
{
	int a = 3, b = 4, c = 5;
/*
	[=, &b]()->void
	{
		b = 7;
		cout << a << " " << b << " " << c << endl;
	}();
*/
	class lambda1
	{
	private:
		int a;
		int& b;
		int c;
	public:
		lambda1(int v1, int& v2, int v3)
			: a(v1)
			, b(v2)
			, c(v3)
		{
			
		}
		~lambda1()
		{

		}
		// 函数调用运算符，他可以传入任意个参数
		void operator ()()
		{
			b = 7;
			cout << a << " " << b << " " << c << endl;
		}
	};
	lambda1(a, b, c)();
	cout << b << endl;
	return EXIT_SUCCESS;
}
