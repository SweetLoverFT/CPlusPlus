#include <string>
#include <iostream>
#define MAX_SIZE 5
using namespace std;

// 概念就像灵魂一样，不可能拥有实体，也不可能一下子变成实体
class CAnimal	// 概念名词“动物”不可以行动，行动
{
public:
	string m_strName;	// 属性包装起来，就像电流一样，不包皮直接摸电线电死你
public:
	enum EType
	{
		ANIMAL_CAT,
		ANIMAL_COCK
	};
public:
	CAnimal(string name){ m_strName = name; }
	virtual ~CAnimal(){}
	virtual void Action() = 0;	// 一旦使用了虚函数，那么析构函数必须要用虚函数
};

class CCat
	: public CAnimal
{
public:
	CCat(string name) : CAnimal(name){ m_strName = name; }
	virtual ~CCat(){}
	virtual void Action(){ cout << m_strName << "蹦蹦跳！\n"; }
};

class CCock
	: public CAnimal
{
public:
	CCock(string name) : CAnimal(name){ m_strName = name; }
	virtual ~CCock(){}
	virtual void Action(){ cout << m_strName << "喔喔叫！\n"; }
};

int main()
{
	// CAnimal animal;				// 抽象类不能实例化对象，必须借助派生类实例化
	int i, choice;
	CAnimal *pArrAnimal[MAX_SIZE];	// 多态就是挂羊头卖狗肉
	for (i = 0; i < MAX_SIZE; i++)
	{
		cin >> choice;
		switch (choice)
		{
		case CAnimal::EType::ANIMAL_CAT:
			pArrAnimal[i] = new CCat("小猫");
			break;
		case CAnimal::EType::ANIMAL_COCK:
			pArrAnimal[i] = new CCock("公鸡");
			break;
		}
	}

	cout << sizeof(pArrAnimal[0]) << endl;
//	cout << &(pArrAnimal[0]->__vfptr) << endl;
	cout << (size_t)(&(((CCat*)nullptr)->m_strName)) << endl;
	cout << (size_t)(&(((CCock*)nullptr)->m_strName)) << endl;

	for (i = 0; i < MAX_SIZE; i++)
		pArrAnimal[i]->Action();			// 每个动物各司其职，干他该干的事情去了

	return EXIT_SUCCESS;
}
