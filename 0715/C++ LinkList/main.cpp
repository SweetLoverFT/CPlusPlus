#include <iostream>
using namespace std;

// ·ºÐÍ
template <typename T>
struct SLinkList
{
	T nVal;
	struct SLinkList *pNext;
};

template <typename T>
SLinkList<T>* Init(int n)
{
	T data;
	int i = 1;
	SLinkList<T> *pHead, *pTmp;
	pHead = pTmp = (SLinkList<T>*)malloc(sizeof(SLinkList<T>));
	cin >> data;
	pTmp->nVal = data;
	while (i++ < n)
	{
		pTmp->pNext = (SLinkList<T>*)malloc(sizeof(SLinkList<T>));
		pTmp = pTmp->pNext;
		cin >> data;
		pTmp->nVal = data;
	}
	pTmp->pNext = NULL;
	return pHead;
}

template <typename T>
void ShowList(SLinkList<T> *pHead)
{
	while (pHead)
	{
		cout << pHead->nVal << " ";
		pHead = pHead->pNext;
	}
	cout << endl;
}

template <typename T>
void FreeList(SLinkList<T> *pHead)
{
	SLinkList<T> *pTmp;
	while (pHead)
	{
		pTmp = pHead->pNext;
		free(pHead);
		pHead = pTmp;
	}
}

enum EType
{
	TYPE_INT = 1,
	TYPE_DOUBLE
};

int main()
{
	int n, choice;
	cin >> choice >> n;
	if (choice == EType::TYPE_INT)
	{
		SLinkList<int> *pHead;
		pHead = Init<int>(n);
		ShowList(pHead);
		FreeList(pHead);
	}
	else if (choice == EType::TYPE_DOUBLE)
	{
		SLinkList<double> *pHead;
		pHead = Init<double>(n);
		ShowList(pHead);
		FreeList(pHead);
	}
	
	return 0;
}
