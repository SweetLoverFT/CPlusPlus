#pragma once

#include <string>

#pragma pack(push)
#pragma pack(1)
class CSLProtocol
{
private:
	static short s_nCnt;
	unsigned char m_sMagicNum[2];	// 0xAA, 0x55
	unsigned short m_nCnt;			// ������
	unsigned short m_cCheckSum;		// У���
	unsigned char m_cCmd;			// ����
	unsigned char m_cResponse;		// Ӧ��
	std::string m_sInfo;			// ��Ϣ������
public:
	CSLProtocol();
	~CSLProtocol();
};
#pragma pack(pop)
