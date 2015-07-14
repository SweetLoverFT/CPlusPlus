#pragma once

// 继承可以继承类所属的，继承成员所属的，派生类就不需要重新定义那些字段
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
