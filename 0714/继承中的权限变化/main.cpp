#include <iostream>
#include "GrandChild1.h"
#include "GrandChild2.h"
#include "GrandChild3.h"
using namespace std;

int main()
{
	// ���� private ���͵ĳ�Ա�������κ�һ�ּ̳з�ʽ����̳�ʧ��
	// �����޷�������ĳ�Ա�����ڲ������ʸ���� private ����
	CChild1 child1(3, 4, 5, 6, 7);
	CChild2 child2(1, 2, 8, 9, 10);
	CChild3 child3(11, 12, 13, 14, 15);

	// ˽�еĶ����ܷ��ʣ�����Ŀ��Ʒ���Ȩ��
	// child1.m_nVal;
	// child2.m_nVal;
	// child3.m_nVal;

	// �ⲿ����ֱ�ӷ��� private �� protected
	// child1.m_nYear;		// private �̳У��ᵼ�¸��ഫ�����κζ����������ռ�����Ӳ�������
	// child1.ShowPos();	// private �̳У���Ѹ��ഫ���� protected �Լ� public �����Ϊ protected
	// child2.m_nYear;		// protected �̳У��ᵼ�¸��ഫ�����κζ��������൱������֮��
	// child2.ShowPos();	// protected �̳У���Ѹ��ഫ���� protected �Լ� public �����Ϊ protected
	// child3.m_nYear;		// public �̳У����ı�ԭ�����ԵĿ��Ʒ���Ȩ��
	child3.ShowPos();

	CGrandChild1 gc1(3, 4, 5, 6, 7);
	CGrandChild2 gc2(1, 2, 8, 9, 10);
	CGrandChild3 gc3(11, 12, 13, 14, 15);

	// gc1.ShowPos();		// ���ܵ���
	// gc2.ShowPos();		// ���ܵ���
	gc3.ShowPos();			// ���Ե���
	return EXIT_SUCCESS;
}
