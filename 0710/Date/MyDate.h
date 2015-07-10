#pragma once

// 行为就像插头，属性就像电流
class CMyDate
{
// 属性
private:
	int m_nYear;	// 年
	int m_nMonth;	// 月
	int m_nDay;		// 日
// 行为
public:
	// 构造函数就是对象创建时，内存排布的初始化，没有返回值，函数名和类名相同
	// CMyDate();
	CMyDate(int year = 0, int month = 0, int day = 0);
	// 赋值构造函数，就是对 = 的重载
	CMyDate& operator = (const CMyDate& obj);
	// 拷贝构造函数
	CMyDate(const CMyDate& obj);
	// 析构函数就是对象死亡时，要做的善后处理，钱生不带来死不带去，钱比作对象在生命期间在堆上创建的内存
	~CMyDate();
	// 属性设置器
	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);
	// 属性访问器
	// const 只能用于修饰成员函数，成员函数就是类里面绑定的函数
	// const 修饰表示这个成员函数是一个常函数，常函数不可以修改属性的数值，常函数只能访问不能修改
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
public:
	// 距离公元元年 3 月 1 日多少天
	int FromThatDay() const;
	// 距离某天共计多少天
	int FromThatDay(const CMyDate& obj) const;
	int FromThatDay(int year, int month, int day) const;
	static int FromThatDay(const CMyDate& obj1, const CMyDate& obj2);
	static int FromThatDay(int year1, int month1, int day1, int year2, int month2, int day2);
	// 运算符重载
	int operator -(const CMyDate& obj) const;
	CMyDate& operator +=(int day);
	// int operator -(int day);		// 作业
	// 隐式转换函数被我们重载了
	operator int();
//	static int operator -(const CMyDate& obj1, const CMyDate& obj2);
//	friend int operator -(const CMyDate& obj1, const CMyDate& obj2);

	// 输出必须用友元，如果用成员函数重载，那么对象是左操作数
	// 好比：CMyDate date，成员重载 this 指针输出效果就是这样输出的 date <<
	friend std::ostream& operator <<(std::ostream& out, const CMyDate& obj);
};

// 非友元也行的原因是，我们调用的是接口 FromThatDay，接口是 public
// int operator -(const CMyDate& obj1, const CMyDate& obj2);
