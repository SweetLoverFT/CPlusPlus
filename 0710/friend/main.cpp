#include "Test.h"

int main()
{
	CMyPoint pt(3, 4);
	CMyVec2 vec2(5, 6);
	CTest t;
	// ֤����Ԫ�ͱ����޹أ�����Ӧ����ô��ӡ
	// CMyPoint::Print(pt)	�� Print Ϊ��̬����ʱ
	// pt.Print();
	Print(pt);				// ��Ԫ�������ʽ��û�� this��Ҳû���� CMyPoint:: ������
	pt.Print();				// ��Ա�����ģ��� this
	CMyPoint::Print(pt);	// ��������ʽ��Ҳû�� this����������Ϊ�����ģ�壬�ǲ��ǿ���ֱ�ӷ��ʣ�����

	t.Print(pt);			// ��Ԫ��ĳ�Ա���������ʽ
	CTest::OutPut(pt);		// ��Ԫ����ຯ�������ʽ

	// ��Ԫ�������ܶž���Ϊ���ѵ��������Ϊ��ʮ�����ص��ƻ�����ķ�װ��
	pt.Print(vec2);
	vec2.Print(pt);
	return 0;
}
