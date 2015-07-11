#include <iostream>
#include "Goods.h"

using namespace std;

// 类的属性快速编码步骤：
// 1.把类的属性抄过来
// 2.去掉 static，并且加上作用域
// 3.初始化
int CGoods::s_nID = 0;
int CGoods::s_nUsedNum = 0;

CGoods::CGoods(std::string sBrand /* = "" */, int nPrice /* = 0 */)
	: m_sBrand(sBrand)
	, m_nPrice(nPrice)
{
	s_nID++;		// 序列号记录，生产了第几个商品
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
