#pragma once

class CValue
{
private:
	int m_nVal;
public:
	// explicit ��ֹ���������캯����ʽת��
	/*explicit */CValue(int val);
	~CValue();
	void SetVal(int value);
	int GetValue() const;
};

