#include <iostream>
using namespace std;

const int LENGTH = 10;

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	// int(A::*pFun)(int, int) = A::Add;
	// cocos2d::Label *label
	// auto label = cocos2d::Label::create();
	auto pFunc = Add;
	cout << pFunc(3, 4) << endl;

	// auto ���ܣ�
	// 1.��������ǰ�Ὠ���ڵȺ�/ð���ұ�����ȷ��
	// 2.���������������е�Ԫ�أ����Ͽ��������飬C ���Ե�һά���飬�������±�Խ��
	int arr[LENGTH];
	for (auto& element : arr)		// ���Ҫ�޸���ֵ������Ҫ�� &
		cin >> element;
	for (auto& element : arr)
		cout << element << " ";
	cout << endl;
	return EXIT_SUCCESS;
}
