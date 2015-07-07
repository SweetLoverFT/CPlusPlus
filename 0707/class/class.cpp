#include <iostream>
using namespace std;

// 富一代
class GrandFather
{
protected:
	int m_nMoney;		// 立遗嘱
public:
	GrandFather(int money){ m_nMoney = money; }
	void SetRestMoney(int money){ m_nMoney -= money; }
	int GetMoney(){ return m_nMoney; }
	~GrandFather(){}
};

// 富二代
class Father
	: public GrandFather
{
protected:
	int m_nMoney;
public:
	Father(int money) : GrandFather(money){ m_nMoney = money; }
//	Father(const GrandFather &obj) : GrandFather(m_nMoney), m_nFatherMoney(m_nMoney){}
	~Father(){}
	void ShowMoney(){ cout << m_nMoney << endl; }
};

// 富三代
class Child
	: public Father
{
protected:
	int m_nMoney;
public:
	Child(int money) : Father(money){ m_nMoney = money; }
	~Child(){}
};

int main()
{
	// 一个家族三代的命运
	GrandFather gf(1000000);
	gf.SetRestMoney(60000);
	Father f(gf.GetMoney());
	f.ShowMoney();
	f.SetRestMoney(600000);
	Child c(f.GetMoney());
	c.ShowMoney();
	if (is_convertible<decltype(c), decltype(f)>::value)
		cout << "c 是他老爸 f 的亲生孩子\n";
	return EXIT_SUCCESS;
}
