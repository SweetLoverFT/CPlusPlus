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
	// C �����󳤶�
#include <tchar.h>
#include <string.h>
	int len = strlen("I love you!");
	int length = wcslen(L"�Ұ���");
	if (strlen(s1) - �Ѿ�ռ�õ��ַ����� >= strlen(s2))
		strcat(s1, s2);		// ƴ�������������� s1 ��ʣ�೤�Ȳ������ s2
	else
	{
		tmp = malloc();		// ���·����ڴ�
		strcpy(tmp, s1);	// ����ԭ������
		strcat(tmp, s2);	// ƴ��
		free(s1);			// ɾ�����ڴ�
		s1 = tmp;			// �ı�ԭ�ָ��ָ��
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
