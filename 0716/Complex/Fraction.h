#pragma once

class CFraction
{
private:
	int m_nNum;		// ����
	int m_nDen;		// ��ĸ
private:
	void Simplify();					// ����
public:
	CFraction(int nNum = 0, int nDen = 1);		// ����Ĺ��캯��
	CFraction(double dbVal);			// ���������캯�������ڰ� double ת���� CFraction
//	CFraction(const CFraction& obj);	// �������캯��
	~CFraction();
//	CFraction& operator =(const CFraction& obj);	// ��ֵ���캯��
	CFraction operator +(const CFraction& obj);		// + ����
	CFraction operator -(const CFraction& obj);		// - ����
	CFraction operator *(const CFraction& obj);		// * ����
	CFraction operator /(const CFraction& obj);		// / ����
	friend std::istream& operator >>(std::istream& in, CFraction& obj);
	friend std::ostream& operator <<(std::ostream& out, const CFraction& obj);
};

