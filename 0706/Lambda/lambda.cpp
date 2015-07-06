#include <iostream>
using namespace std;

int Add(int a, int b)
{
	return a + b;
}

void Print()
{
	cout << "Hello, world!\n";
}

int main()
{
	Print();

	// Lambda ���ʽ��һ����ʽΪ��
	// [capture](param)modifier->return type{body}
	// [ �����б� ]( ��������б� ) ���η� -> ����ֵ���� { ������ };
	// int Add(int a, int b){return a + b;}
	// <����ֵ> ������(��������б�) ���η� {������}
	[]()
	{
		cout << "Hello, world!\n";
	}();			// () �Ǻ������������

	auto p1 = []() -> void
	{
		cout << "Hello, world!\n";
		cout << __FUNCTION__ << endl;
	};
	cout << typeid(p1).name() << endl;
	p1();			// () �Ǻ������������

	auto p2 = [](int a, int b) -> int { return a + b; };
	cout << p2(3, 4) << endl;

	int a, b;
	cin >> a >> b;
	cout << [](int a, int b)->int
	{
		a = 3, b = 4;
		return a + b;
	}(a, b) << endl;
	cout << a << " " << b << endl;

	{
		int a, b;
		cin >> a >> b;
	}

	// ������Ų�����Ǻ���� Lambda ���ʽͬ���ֿռ�������Ǹ�����
	// [capture] ���õ���ֵ���ݷ�ʽ������������ Lambda �����ڲ��� a �� b �Ǹ���
	// �����޸Ĳ���Ӱ��ԭ��
	// �������б�ǿյ�ʱ�����η� const��mutable��throw �ȹؼ��־Ϳ���ʹ��
	// ��Щ���η��Ǻ�[�����б�]�������б�Ϊ�ղ����޸����η�
	cout << [a, b]()mutable->int
	{
		a = 3, b = 4;
		return a + b;
	}() << endl;
	cout << a << " " << b << endl;

	// �����б�������õķ�ʽ����
	cout << [&a, &b]()->int
	{
		a = 3, b = 4;
		return a + b;
	}() << endl;
	cout << a << " " << b << endl;

	int c, d, e, f;
	cin >> c >> d >> e >> f;

	// ����������࣬����һ��������ֵ���ݷ�ʽ����ᵼ�²����б������
	// [a, b, c, d, e, f]
	cout << [a, b, c, d, e, f]()->int
	{
		return a + b + c + d + e + f;
	}() << endl;

	// �����б��� = �����ã��ѿɼ����ڲ������б�����������ֵ���ݵķ�ʽ����
	cout << [=]()->int
	{
		return a + b + c + d + e + f;
	}() << endl;

	// �����б��� & �����ã��ѿɼ����ڵ����б����������ý���
	cout << [&]()->int
	{
		return a + b + c + d + e + f;
	}() << endl;

	// ��ϲ���
	[&a, b](){};		// ���� a�������õķ�ʽ���񣬶��� b����ֵ���ݵķ�ʽ����
	[&, a](){};			// ���� a��ʹ��ֵ���ݷ�ʽ���񣬶��ڿɼ����������Ķ���һ�ɲ������õķ�ʽ����
	[=, &b](){};		// ���� b��ʹ�����÷�ʽ���񣬶��ڿɼ����������Ķ���һ�ɲ���ֵ���ݵķ�ʽ����

	return EXIT_SUCCESS;
}
