#include <istream>
#include <ostream>
#include <sstream>
#include "MyArray.h"

using namespace std;

CMyArray::CMyArray(int nSize)
	: m_nSize(nSize)
{
	m_pnArr = new int[m_nSize];
	memset(m_pnArr, 0, m_nSize);
}

CMyArray::CMyArray(const CMyArray& obj)
	: m_nSize(obj.m_nSize)
{
	m_pnArr = new int[m_nSize];
	memcpy(m_pnArr, obj.m_pnArr, m_nSize);
}

CMyArray::~CMyArray()
{
	delete[] m_pnArr;
}

int& CMyArray::operator [](int nIndex)
{
	if (nIndex >= m_nSize || nIndex < 0)
		throw "Exception: Out of range!";

	return m_pnArr[nIndex];
}

CMyArray& CMyArray::operator =(const CMyArray& obj)
{
	m_nSize = obj.m_nSize;
	m_pnArr = new int[m_nSize];
	memcpy(m_pnArr, obj.m_pnArr, m_nSize);
	return *this;
}

istream& operator >>(istream& in, CMyArray& obj)
{
	int i;
	for (i = 0; i < obj.m_nSize; i++)
	{
		if (!(in >> obj.m_pnArr[i]))
		{
			in.setstate(in.failbit);
			in.unget();
			break;
		}
	}

	return in;
}

ostream& operator <<(ostream& out, CMyArray& obj)
{
	int i;
	ostringstream tmp;
	for (i = 0; i < obj.m_nSize; i++)
		tmp << obj.m_pnArr[i] << " ";
	tmp << endl;
	out << tmp.str();
	return out;
}
