#include <string>
#include <iostream>
using namespace std;

void Print()
{
	cout << "Hello, world!\n";
}

// ���������Ĭ�ϲ�������ô�����ܲ�Ҫ���������ĺ��������������������Ե�Σ��
// ������Ĭ�ϲ����ĺ��������Ǿ������ṩһ���������ĺ�����Ϊͳһ�Ľӿھ�����
void Print(string s = "SweetLover")
{
	cout << s << endl;
}

int main()
{
	Print();	// ���������
	return EXIT_SUCCESS;
}
