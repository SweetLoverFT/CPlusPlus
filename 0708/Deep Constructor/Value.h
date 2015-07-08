#pragma once

class CValue
{
private:
	int *m_pnNum;
public:
	CValue(int val);
	CValue(const CValue& obj);	// 我们要用深拷贝构造函数实现它
	~CValue();
	int GetValue() const;
};

