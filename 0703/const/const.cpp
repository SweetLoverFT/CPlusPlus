#include <iostream>
using namespace std;

int main()
{
	// C++ �У�const ��ʾֻ�����η������εĲ�����������������εĶ����ǵ�ַ
	const int LENGTH = 5;
	int arr[LENGTH];
	int *p = const_cast<int*>(&LENGTH);
	*p = 3;
	cout << LENGTH;
	return EXIT_SUCCESS;
}