#pragma once

#include <string>

#pragma pack(push)
#pragma pack(1)
class CSLProtocol
{
private:
	static short s_nCnt;
	unsigned char m_sMagicNum[2];	// 0xAA, 0x55
	unsigned short m_nCnt;			// 计数器
	unsigned short m_cCheckSum;		// 校验和
	unsigned char m_cCmd;			// 命令
	unsigned char m_cResponse;		// 应答
	std::string m_sInfo;			// 信息，反馈
public:
	CSLProtocol();
	~CSLProtocol();
};
#pragma pack(pop)
