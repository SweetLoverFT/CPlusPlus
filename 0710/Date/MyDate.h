#pragma once

// ��Ϊ�����ͷ�����Ծ������
class CMyDate
{
// ����
private:
	int m_nYear;	// ��
	int m_nMonth;	// ��
	int m_nDay;		// ��
// ��Ϊ
public:
	// ���캯�����Ƕ��󴴽�ʱ���ڴ��Ų��ĳ�ʼ����û�з���ֵ����������������ͬ
	// CMyDate();
	CMyDate(int year = 0, int month = 0, int day = 0);
	// ��ֵ���캯�������Ƕ� = ������
	CMyDate& operator = (const CMyDate& obj);
	// �������캯��
	CMyDate(const CMyDate& obj);
	// �����������Ƕ�������ʱ��Ҫ�����ƺ���Ǯ��������������ȥ��Ǯ���������������ڼ��ڶ��ϴ������ڴ�
	~CMyDate();
	// ����������
	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);
	// ���Է�����
	// const ֻ���������γ�Ա��������Ա��������������󶨵ĺ���
	// const ���α�ʾ�����Ա������һ�����������������������޸����Ե���ֵ��������ֻ�ܷ��ʲ����޸�
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
public:
	// ���빫ԪԪ�� 3 �� 1 �ն�����
	int FromThatDay() const;
	// ����ĳ�칲�ƶ�����
	int FromThatDay(const CMyDate& obj) const;
	int FromThatDay(int year, int month, int day) const;
	static int FromThatDay(const CMyDate& obj1, const CMyDate& obj2);
	static int FromThatDay(int year1, int month1, int day1, int year2, int month2, int day2);
	// ���������
	int operator -(const CMyDate& obj) const;
	CMyDate& operator +=(int day);
	// int operator -(int day);		// ��ҵ
	// ��ʽת������������������
	operator int();
//	static int operator -(const CMyDate& obj1, const CMyDate& obj2);
//	friend int operator -(const CMyDate& obj1, const CMyDate& obj2);

	// �����������Ԫ������ó�Ա�������أ���ô�������������
	// �ñȣ�CMyDate date����Ա���� this ָ�����Ч��������������� date <<
	friend std::ostream& operator <<(std::ostream& out, const CMyDate& obj);
};

// ����ԪҲ�е�ԭ���ǣ����ǵ��õ��ǽӿ� FromThatDay���ӿ��� public
// int operator -(const CMyDate& obj1, const CMyDate& obj2);
