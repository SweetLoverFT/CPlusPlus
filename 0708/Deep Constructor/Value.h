#pragma once

class CValue
{
private:
	int *m_pnNum;
public:
	CValue(int val);
	CValue(const CValue& obj);	// ����Ҫ��������캯��ʵ����
	~CValue();
	int GetValue() const;
};

