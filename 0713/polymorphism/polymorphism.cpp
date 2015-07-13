#include <string>
#include <iostream>
#define MAX_SIZE 5
using namespace std;

// ����������һ����������ӵ��ʵ�壬Ҳ������һ���ӱ��ʵ��
class CAnimal	// �������ʡ�����������ж����ж�
{
public:
	string m_strName;	// ���԰�װ�������������һ��������Ƥֱ�������ߵ�����
public:
	enum EType
	{
		ANIMAL_CAT,
		ANIMAL_COCK
	};
public:
	CAnimal(string name){ m_strName = name; }
	virtual ~CAnimal(){}
	virtual void Action() = 0;	// һ��ʹ�����麯������ô������������Ҫ���麯��
};

class CCat
	: public CAnimal
{
public:
	CCat(string name) : CAnimal(name){ m_strName = name; }
	virtual ~CCat(){}
	virtual void Action(){ cout << m_strName << "�ı�����\n"; }
};

class CCock
	: public CAnimal
{
public:
	CCock(string name) : CAnimal(name){ m_strName = name; }
	virtual ~CCock(){}
	virtual void Action(){ cout << m_strName << "�฽У�\n"; }
};

int main()
{
	// CAnimal animal;				// �����಻��ʵ�������󣬱������������ʵ����
	int i, choice;
	CAnimal *pArrAnimal[MAX_SIZE];	// ��̬���ǹ���ͷ������
	for (i = 0; i < MAX_SIZE; i++)
	{
		cin >> choice;
		switch (choice)
		{
		case CAnimal::EType::ANIMAL_CAT:
			pArrAnimal[i] = new CCat("Сè");
			break;
		case CAnimal::EType::ANIMAL_COCK:
			pArrAnimal[i] = new CCock("����");
			break;
		}
	}

	cout << sizeof(pArrAnimal[0]) << endl;
//	cout << &(pArrAnimal[0]->__vfptr) << endl;
	cout << (size_t)(&(((CCat*)nullptr)->m_strName)) << endl;
	cout << (size_t)(&(((CCock*)nullptr)->m_strName)) << endl;

	for (i = 0; i < MAX_SIZE; i++)
		pArrAnimal[i]->Action();			// ÿ�������˾��ְ�������øɵ�����ȥ��

	return EXIT_SUCCESS;
}
