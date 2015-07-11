#include <iostream>
#include "Goods.h"

using namespace std;

enum EStatus
{
	STATUS_USED = 1,
	STATUS_KEEP
};

// C++ 面向对象编程要领：
// 大范围的，考虑面向对象的架构
// 具体到某个函数的时候，切换成面向过程：生产、使用、统计、释放
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
	// 类的函数，我们直接用“类名::函数名”
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
