#pragma once

class CMyArray
{
private:
	int m_nSize;
	int *m_pnArr;
public:
	CMyArray(int nSize);
	CMyArray(const CMyArray& obj);
	~CMyArray();
	int& operator [](int nIndex);
	CMyArray& operator =(const CMyArray& obj);
	friend std::istream& operator >>(std::istream& in, CMyArray& obj);
	friend std::ostream& operator <<(std::ostream& out, CMyArray& obj);
};

