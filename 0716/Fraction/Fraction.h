#pragma once

class CFraction
{
private:
	int m_nNum;		// 分子
	int m_nDen;		// 分母
private:
	void Simplify();					// 化简
public:
	CFraction(int nNum = 0, int nDen = 1);		// 常规的构造函数
	CFraction(double dbVal);			// 单参数构造函数，用于把 double 转换成 CFraction
//	CFraction(const CFraction& obj);	// 拷贝构造函数
	~CFraction();
//	CFraction& operator =(const CFraction& obj);	// 赋值构造函数
	CFraction operator +(const CFraction& obj);		// + 运算
	CFraction operator -(const CFraction& obj);		// - 运算
	CFraction operator *(const CFraction& obj);		// * 运算
	CFraction operator /(const CFraction& obj);		// / 运算
	friend std::istream& operator >>(std::istream& in, CFraction& obj);
	friend std::ostream& operator <<(std::ostream& out, const CFraction& obj);
};

