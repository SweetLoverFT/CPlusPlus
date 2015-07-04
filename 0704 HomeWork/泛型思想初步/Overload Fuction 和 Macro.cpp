#include <string>
#include <iostream>
using namespace std;

enum EType
{
	TYPE_INT,
	TYPE_DOUBLE,
	TYPE_STRING
};

int Add(int, int);
double Add(double, double);
string Add(string, string);

int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

// string ����ֱ����ӣ�����Ϊ�Ѿ��������������
string Add(string a, string b)
{
	return a + b;
}

// C ���Եĺ겻������������ԣ�����Ѿ��л����ķ���˼��������
// �겻֧�ֵ��ԣ�����������������˽�г�Ա���ⲿ����ֱ�ӷ��ʣ�ǣ�浽Ȩ�����⣬��ô��������
// �겻��ȫ
#define ADD(num1, num2) \
	num1 + num2

// #define CALC(a, b) a + b
// ������ CALC(3, 4) * CALC(1, 2) ���ǲ���ȫ��
// ����ĺ��滻���ǰ����������滻����������������������ʽ����ֵ�������滻
#define MAX(a, b) ( ( (a) > (b) ) ? (a) : (b) )

int main()
{
	int type;
	cout << "Please input data type(0:INT 1:DOUBLE 2:STRING):";
	cin >> type;
/*
	switch (type)
	{
	case TYPE_INT:
		{
			int a, b;
			cin >> a >> b;
			cout << Add(a, b);
		}
		break;
	case TYPE_DOUBLE:
		{
			double a, b;
			cin >> a >> b;
			cout << Add(a, b);
		}
		break;
	case TYPE_STRING:
		{
			string a, b;
			cin >> a >> b;
			cout << Add(a, b);
		}
		break;
	}
*/
	switch (type)
	{
	case TYPE_INT:
		{
			int a, b;
			cin >> a >> b;
			cout << ADD(a, b);
		}
		break;
	case TYPE_DOUBLE:
		{
			double a, b;
			cin >> a >> b;
			cout << ADD(a, b);
		}
		break;
	case TYPE_STRING:
		{
			string a, b;
			cin >> a >> b;
			cout << ADD(a, b);
		}
		break;
	}

	double a, b;
	cin >> a >> b;
	cout << MAX(a++, b++) << endl;
	return EXIT_SUCCESS;
}
