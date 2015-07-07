#include <afx.h>
#include <afxstr.h>	// CString
#include <iostream>
using namespace std;

// #undef _tWinMain

/*
class A
	: public int
{

};
*/

int main()
{
	CString s;
	s = _T("I love");
	s += _T(" you");
	/*
	// C 语言求长度
#include <tchar.h>
#include <string.h>
	int len = strlen("I love you!");
	int length = wcslen(L"我爱你");
	if (strlen(s1) - 已经占用的字符个数 >= strlen(s2))
		strcat(s1, s2);		// 拼接有隐患，假如 s1 的剩余长度不够存放 s2
	else
	{
		tmp = malloc();		// 重新分配内存
		strcpy(tmp, s1);	// 复制原有内容
		strcat(tmp, s2);	// 拼接
		free(s1);			// 删除旧内存
		s1 = tmp;			// 改变原宥指针指向
	}
	*/
	OutputDebugString(s);
// 	for (int i = 0; i < s.GetLength(); i++)
// 		cout << (wchar_t)s[i];
	cout << endl << s.GetLength() << endl;

	s = "abc";
	OutputDebugString(s);
	return EXIT_SUCCESS;
}
