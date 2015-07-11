#include <iostream>
#include "Goods.h"

using namespace std;

enum EStatus
{
	STATUS_USED = 1,
	STATUS_KEEP
};

// C++ ���������Ҫ�죺
// ��Χ�ģ������������ļܹ�
// ���嵽ĳ��������ʱ���л���������̣�������ʹ�á�ͳ�ơ��ͷ�
int main()
{
	string sBrand;
	CGoods **ppGoods;
	int i, n, nPrice, nUsed;
	cin >> n;
	ppGoods = new CGoods *[n];
	for (i = 0; i < n; i++)
	{
		cin >> nPrice >> sBrand;
		ppGoods[i] = new CGoods(sBrand, nPrice);
		cin >> nUsed;
		if (nUsed == EStatus::STATUS_USED)
		{
			delete ppGoods[i];
			ppGoods[i] = nullptr;
		}
	}
	// ��ĺ���������ֱ���á�����::��������
	cout << "Total produced " << CGoods::GetTotalGoods() << " products, "
		<< CGoods::GetTotalUsedGoods() << " products are in using!\n";
	for (i = 0; i < n; i++)
	{
		delete ppGoods[i];
		ppGoods[i] = nullptr;
	}

	cout << sizeof(CGoods) << endl;
	cout << "Total produced " << CGoods::GetTotalGoods() << " products, "
		<< CGoods::GetTotalUsedGoods() << " products are in using!\n";
	return EXIT_SUCCESS;
}
