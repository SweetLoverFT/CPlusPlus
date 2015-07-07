#include <string>
#include <iostream>
#define MAX_SIZE 5
using namespace std;

// ����������һ����������ӵ��ʵ�壬Ҳ������һ���ӱ��ʵ��
class CAnimal	// �������ʡ�����������ж����ж�
{
private:
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
private:
	string m_strName;
public:
	CCat(string name) : CAnimal(name){ m_strName = name; }
	virtual ~CCat(){}
	virtual void Action(){ cout << m_strName << "�ı�����\n"; }
};

class CCock
	: public CAnimal
{
private:
	string m_strName;
public:
	CCock(string name) : CAnimal(name){ m_strName = name; }
	virtual ~CCock(){}
	virtual void Action(){ cout << m_strName << "�฽У�\n"; }
};

int main()
{
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

	for (i = 0; i < MAX_SIZE; i++)
		pArrAnimal[i]->Action();			// ÿ�������˾��ְ�������øɵ�����ȥ��

	return EXIT_SUCCESS;
}
