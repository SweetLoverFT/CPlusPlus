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
};
