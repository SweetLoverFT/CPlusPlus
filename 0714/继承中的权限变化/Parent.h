#pragma once

// �̳п��Լ̳��������ģ��̳г�Ա�����ģ�������Ͳ���Ҫ���¶�����Щ�ֶ�
class CParent
{
private:
	int m_nX;
	int m_nY;
protected:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
public:
	CParent(int x, int y, int year, int month, int day);
	~CParent();
	void ShowPos() const;
	void ShowDate() const;
};
