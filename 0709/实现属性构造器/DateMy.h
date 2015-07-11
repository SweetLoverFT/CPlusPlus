#pragma once

#define PROPERTY(__TYPE__, __NAME__, __MEMBER__) \
public: \
	__TYPE__ Get##__NAME__() const \
	{ \
		return __MEMBER__; \
	} \
	void Set##__NAME__(__TYPE__ __NAME__) \
	{ \
		__MEMBER__ = __NAME__; \
	}

class CDateMy
{
	// ����
private:
	int m_nYear;	// ��
	int m_nMonth;	// ��
	int m_nDay;		// ��
	// ��Ϊ
public:
	CDateMy(int year = 0, int month = 0, int day = 0);
	~CDateMy();
	PROPERTY(int, Year, m_nYear);
	PROPERTY(int, Month, m_nMonth);
	PROPERTY(int, Day, m_nDay);
};

