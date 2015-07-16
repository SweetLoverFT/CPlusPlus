#include <iostream>
using namespace std;

// C 语言的泛型
#define LinkList(__TYPE__) \
struct LinkList##__TYPE__ \
{ \
	__TYPE__ nVal; \
	struct LinkList *pNext; \
}

#define CONNECT_TYPE(__TYPE__) \
	LinkList##__TYPE__

enum EType
{
	TYPE_INT = 1,
	TYPE_DOUBLE
};

LinkList(int);
LinkList(double);

#define INIT(__TYPE__) \
CONNECT_TYPE(__TYPE__)* Init(int n) \
{ \
	__TYPE__ data; \
	int i = 1; \
	CONNECT_TYPE(__TYPE__) *pHead, *pTmp; \
	pHead = pTmp = (CONNECT_TYPE(__TYPE__) *)malloc(sizeof(CONNECT_TYPE(__TYPE__))); \
	cin >> data; \
	pTmp->nVal = data; \
	while (i++ < n) \
	{ \
		pTmp->pNext = (CONNECT_TYPE(__TYPE__) *)malloc(sizeof(CONNECT_TYPE(__TYPE__))); \
		pTmp = pTmp->pNext; \
		scanf("%d", &data); \
		pTmp->nVal = data; \
	} \
	pTmp->pNext = NULL; \
	return pHead; \
}

#define SHOW_LIST(__TYPE__) \
void ShowList(CONNECT_TYPE(__TYPE__) *pHead) \
{ \
	while (pHead) \
	{ \
		cout << pHead->nVal; \
		pHead = pHead->pNext; \
	} \
	cout << endl; \
}


#define FREE_LIST(__TYPE__) \
void FreeList(CONNECT_TYPE(__TYPE__) *pHead) \
{ \
	CONNECT_TYPE *pTmp; \
	while (pHead) \
	{ \
		pTmp = pHead->pNext; \
		free(pHead); \
		pHead = pTmp; \
	} \
}

INIT(int)
INIT(double)
SHOW_LIST(int)
SHOW_LIST(double)
FREE_LIST(int)
FREE_LIST(double)

int main()
{
	// 输入 1，生产 int 链表
	// 输入 2，生产 double 链表
	int choice, n;
	cin >> choice >> n;
	if (choice == EType::TYPE_INT)
	{
		LinkList(int) *l;
		l = Init(n);
	}
	else if (choice == EType::TYPE_DOUBLE)
	{
		LinkList(double) *l;
	}
}
