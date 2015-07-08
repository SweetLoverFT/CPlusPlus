#include <iostream>
#include "MyDate.h"

using namespace std;

int main()
{
	// CMyDate date();		// ���õ��Ǳ�����Ĭ���ṩ��
	CMyDate date1(2015, 7, 8);
	date1.SetYear(2014);
	date1.SetMonth(11);
	date1.SetDay(15);
	cout << "This Date is: " << date1.GetYear() << " year, "
		<< date1.GetMonth() << " month, " << date1.GetDay() << " day\n";

	// CMyDate(const CMyDate&)	�������죬Ĭ�ϲ���ֵ���ݣ�ǳ����
	// CMyDate(int year, int month, int day)	�Լ��������ͨ�Ĺ��캯��
	CMyDate *p = new CMyDate(2013, 4, 27);
	// C++ ���� new �����ڴ���Զ���������ת����Ҳ���ǵ��ù��캯��
	// malloc ֻ�����ڴ棬�����ù��캯��������Ҫǿ��ת��
	// ǿ��ת�����ܻ���ñ������ṩ��Ĭ��ת�����캯����Ĭ��ת�����캯���ǲ���Ϊ��
	delete p;	// C++ ����� delete �������� free ���ͷ��ڴ�Ĺ��ܣ�������������

	// ��ֵ���캯����ʵ�����Ƕ� = ����������أ����⻹��һ��ֵ���ݣ����ǵ�ַ/���ô���
	// CMyDate date2 = date1;	// ��������ն���Ͳ��ø�ֵ���죬��ô��������Ѹ�ֵ�����Ż��ɱ�������Ĭ�Ϲ���
	CMyDate date2;
	date2 = date1;
	date2.SetYear(2012);
	date2.SetMonth(12);
	date2.SetDay(22);
	cout << "This date1 is: " << date1.GetYear() << " year, "
		<< date1.GetMonth() << " month, " << date1.GetDay() << " day\n";
	cout << "This date2 is: " << date2.GetYear() << " year, "
		<< date2.GetMonth() << " month, " << date2.GetDay() << " day\n";

	CMyDate date3(date1);	// ��������
	CMyDate date4 = date1;	// ��ʽ���Ǹ�ֵ���죬����Ϊ������������̳�ʼ�������Ա������Ż�Ϊ��������
	return EXIT_SUCCESS;
}
