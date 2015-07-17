#include <istream>
#include <ostream>
#include <sstream>
#include "Fraction.h"

using namespace std;

CFraction::CFraction(int nNum, int nDen)
{
	if (nDen == 0)
		throw "Error: Denominator cannot be zero!";

	m_nNum = nNum;
	m_nDen = nDen;
	if (m_nDen < 0)
	{
		m_nDen = -m_nDen;
		m_nNum = -m_nNum;
	}
	Simplify();
}

// 只精确到小数点后 6 位
CFraction::CFraction(double dbVal)
	: m_nDen(1e+6)
{
	bool bIsNegative = false;
	if (dbVal < 0.0)
		bIsNegative = true;

	int nInteger = static_cast<int>(dbVal);
	double dbFraction = dbVal - nInteger;
	if (bIsNegative)
		dbFraction = -dbFraction;
	m_nNum = static_cast<int>(dbFraction * m_nDen + 0.5);
	Simplify();
	if (bIsNegative)
		m_nNum = -m_nNum;
	m_nNum += nInteger * m_nDen;
}

CFraction::~CFraction()
{
}

void CFraction::Simplify()
{
	bool bIsNegative = false;
	if (m_nNum < 0)
	{
		m_nNum = -m_nNum;
		bIsNegative = true;
	}

	int nNum = m_nNum, nDen = m_nDen, rest = nNum % nDen;
	while (rest)
	{
		nNum = nDen;
		nDen = rest;
		rest = nNum % nDen;
	}
	m_nNum = m_nNum / nDen;
	m_nDen = m_nDen / nDen;
	if (bIsNegative)
		m_nNum = -m_nNum;
}

CFraction CFraction::operator +(const CFraction& obj)
{
	int nDen = /*this->*/m_nDen * obj.m_nDen;
	int nNum = m_nNum * obj.m_nDen + obj.m_nNum * m_nDen;
	return CFraction(nNum, nDen);
}

CFraction CFraction::operator -(const CFraction& obj)
{
	int nDen = /*this->*/m_nDen * obj.m_nDen;
	int nNum = m_nNum * obj.m_nDen - obj.m_nNum * m_nDen;
	return CFraction(nNum, nDen);
}

CFraction CFraction::operator *(const CFraction& obj)
{
	return CFraction(m_nNum * obj.m_nNum, m_nDen * obj.m_nDen);
}

CFraction CFraction::operator /(const CFraction& obj)
{
	if (obj.m_nNum == 0)
		throw "Error: Obj\'s denominator cannot be zero!";

	return CFraction(m_nNum * obj.m_nDen, m_nDen * obj.m_nNum);
}

istream& operator >>(istream& in, CFraction& obj)
{
	char sep;
	int nNum, nDen;
	if (!(in >> nNum))
	{
		in.setstate(in.failbit);
		return in;
	}

	obj.m_nNum = nNum;
	if (!(in >> sep) || (sep != '/'))
	{
		obj.m_nDen = 1;
		if (sep != '/')
			in.unget();

		return in;
	}
	else if (!(in >> nDen))
	{
		obj.m_nDen = 1;
		in.setstate(in.failbit);
	}
	else if (nDen == 0)
		throw "Error: Denominator cannot be zero!";
	else
		obj.m_nDen = nDen;

	return in;
}

ostream& operator <<(ostream& out, const CFraction& obj)
{
	ostringstream tmp;
	tmp << obj.m_nNum << "/" << obj.m_nDen;
	out << tmp.str();		// 加 '\0'
	return out;
}
