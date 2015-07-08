#pragma once

class CValue
{
private:
	int m_nVal;
public:
	// explicit 防止单参数构造函数隐式转换
	/*explicit */CValue(int val);
	~CValue();
	void SetVal(int value);
	int GetValue() const;
};

