#pragma once

#include <string>

class CGoods
{
private:
	static int s_nID;		// ��Ʒ���к�
	static int s_nUsedNum;	// ��ʹ�õĲ�Ʒ����
	std::string m_sBrand;	// ��Ʒ����
	int m_nPrice;			// ��Ʒ�۸�
public:
	CGoods(std::string sBrand = "", int nPrice = 0);
	~CGoods();
	void SetBrand(std::string sBrand);
	void SetPrice(int nPrice);
	static int GetTotalGoods()/* const*/;		// ��̬����û�� this ָ�룬��˲���ʹ�� const ����
	static int GetTotalUsedGoods();				// ��ǰʹ�õı�ֵƷ
};

