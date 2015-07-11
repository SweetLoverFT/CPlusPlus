#pragma once

class CParent
{
public:
	enum EStatus
	{
		STATUS_NONE,
		STATUS_KEEP,
		STATUS_EARN
	};
private:
	int m_nMoney;
	static EStatus s_eStatus;
protected:
	int m_nRestMoney;
public:
	CParent(int nMoney = 0);
	~CParent();
	void CostMoney(int nMoney = 0);
};

