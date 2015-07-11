#include <iostream>
#include "Goods.h"

using namespace std;

// ������Կ��ٱ��벽�裺
// 1.��������Գ�����
// 2.ȥ�� static�����Ҽ���������
// 3.��ʼ��
int CGoods::s_nID = 0;
int CGoods::s_nUsedNum = 0;

CGoods::CGoods(std::string sBrand /* = "" */, int nPrice /* = 0 */)
	: m_sBrand(sBrand)
	, m_nPrice(nPrice)
{
	s_nID++;		// ���кż�¼�������˵ڼ�����Ʒ
	s_nUsedNum++;
	cout << "Product ID: " << s_nID << ":\n\tBrand = " << m_sBrand << "\n\tPrice = " << m_nPrice << endl;
}

CGoods::~CGoods()
{
	s_nUsedNum--;
	cout << "Used this product:\n\tBrand = " << m_sBrand << "\n\tPrice = " << m_nPrice << endl;
}

void CGoods::SetBrand(string sBrand)
{
	m_sBrand = sBrand;
}

void CGoods::SetPrice(int nPrice)
{
	m_nPrice = nPrice;
}

int CGoods::GetTotalGoods()
{
	return s_nID;
}

int CGoods::GetTotalUsedGoods()
{
	return s_nUsedNum;
}
