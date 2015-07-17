#include <vector>
#include <iostream>
using namespace std;

class CMyObject
{

};

class CBuildingObject
	: public CMyObject
{

};

class CMoveObject
	: public CMyObject
{

};

class CSoldier
	: public CMoveObject
{

};

class CBuildingBase
	: public CBuildingObject
{

};

template <class T>
class CMyVector
{
private:
	vector<T> m_tVec;
public:
	CMyVector()
	{
		static_assert(!is_convertible<T, CMoveObject>::value, "Cannot create queue!");
	}
	~CMyVector() = default;
};

int main()
{
	CMyObject **pObj = new CMyObject *[3];
	pObj[0] = new CBuildingBase();
	pObj[1] = new CSoldier();
	pObj[2] = new CSoldier();

	// CMyVector *pVec = new CMyVector
	static_assert(is_convertible<decltype(*pObj[0]), CMoveObject>::value, "Cannot create queue!");
	return EXIT_SUCCESS;
}
