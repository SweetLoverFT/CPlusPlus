extern "C"
{
	#include "struct.h"
}
#include <iostream>
using namespace std;

// struct �� class �� C++ �е������ǣ�struct Ĭ���� public ����Ȩ��
// class Ĭ���� private ����Ȩ��
// struct ���԰��� C ���Եķ�ʽ�� C++ �б���
struct S2
{
// private:
	int a;
	int b;
	// ���Ժ���Ϊ�������İ󶨵�һ��󣬾Ͳ���Ҫ���ݲ�����
	int Add()
	{
		return a + b;
	}
};

extern "C"
{
	// ��ʽ�� (pdf) �ӿڣ���Ҫ��������� C++ �� C �ӿڵ��õļ���
	typedef struct Point
	{
		int x;
		int y;
	}Point;
}

int main()
{
	S2 s2;
	Point pt;	// Point ������ pt һ���� C ���԰汾��
	Init();
	cin >> s2.a >> s2.b;
	cout << s2.Add() << endl;
	return EXIT_SUCCESS;
}
