#include <iostream>
#include "MyPoint.h"

using namespace std;

CMyPoint::CMyPoint(int x /* = 0 */, int y /* = 0 */)
	: m_nX(x)
	, m_nY(y)
{
}

CMyPoint::~CMyPoint()
{
}

// ��Ԫ��Ϊ�Ǳ���ķ����ߣ�����Ҫ����������ȥ������
void Print(const CMyPoint& obj)
{
	// m_nX ��˽�еģ�����˵�������ⲿֱ�ӷ���
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}

void CMyPoint::Print()
{
	// ��Ա������������ this ָ��
	cout << "(" << this->m_nX << ", " << m_nY << ")\n";
}

void CMyPoint::Print(const CMyVec2& obj)
{
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}

void CMyPoint::Print(const CMyPoint& obj)
{
	// ��������������ʣ���ʵ���ϲ��ǵ�
	// ���еĶ����ǲ��Ƕ���������࣬����������
	cout << "(" << obj.m_nX << ", " << obj.m_nY << ")\n";
}
