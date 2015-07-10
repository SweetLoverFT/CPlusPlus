#include <iostream>
#include "Test.h"

using namespace std;

CTest::CTest()
{
}

CTest::~CTest()
{
}

void CTest::Print(const CMyPoint& obj)
{
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}

void CTest::OutPut(const CMyPoint& obj)
{
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}
