#include "SLProtocol.h"

short CSLProtocol::s_nCnt = 0;

CSLProtocol::CSLProtocol()
	: m_sMagicNum({ 0xAA, 0x55 })
	, m_nCnt(++s_nCnt)
{

}

CSLProtocol::~CSLProtocol()
{
}
