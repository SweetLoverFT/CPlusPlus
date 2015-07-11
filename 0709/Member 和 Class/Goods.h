#pragma once

#include <string>

class CGoods
{
private:
	static int s_nID;		// 商品序列号
	static int s_nUsedNum;	// 被使用的产品个数
	std::string m_sBrand;	// 商品名称
	int m_nPrice;			// 商品价格
public:
	CGoods(std::string sBrand = "", int nPrice = 0);
	~CGoods();
	void SetBrand(std::string sBrand);
	void SetPrice(int nPrice);
	static int GetTotalGoods()/* const*/;		// 静态函数没有 this 指针，因此不能使用 const 修饰
	static int GetTotalUsedGoods();				// 当前使用的保值品
};

