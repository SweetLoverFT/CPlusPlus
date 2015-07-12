#define _CRT_SECURE_NO_WARNINGS
#include "MyFile.h"

using namespace std;

int CMyFile::MAX_SIZE = 0x7FFFFFFF;

string CMyFile::GetMode()
{
	switch (m_eMode)
	{
	case CMyFile::READ:
		return string("r");
	case CMyFile::WRITE:
		return string("w");
	case CMyFile::READ_AND_WRITE:
		return string("a+");
	case CMyFile::APPEND:
		return string("a");
	case CMyFile::BINARY:
		throw "Error mode: Cannot open a file just in BINARY mode!";
		break;
	case CMyFile::TEXT:
		throw "Error mode: Cannot open a file just in TEXT mode!";
		break;
	case CMyFile::READ_BINARY:
		return string("rb");
	case CMyFile::WRITE_BINARY:
		return string("wb");
	case CMyFile::READ_AND_WRITE_BINARY:
		return string("ab+");
	}
}

CMyFile::CMyFile(string sFileName /* = "" */, Mode eMode /* = READ_AND_WRITE */)
	: m_sFileName(sFileName)
	, m_eMode(eMode)
	, m_pf(nullptr)
{
	Open(m_sFileName, m_eMode);
}

CMyFile::~CMyFile()
{

}

CMyFile::BOOL CMyFile::Open(std::string sFileName, Mode eMode /* = READ_AND_WRITE */)
{
	if (sFileName != "")
	{
		Close();
		m_sFileName = sFileName;
		m_eMode = eMode;
		m_pf = fopen(m_sFileName.c_str(), GetMode().c_str());
		if (m_pf == nullptr)
			throw "Failed to open file!";
	}

	return EXIT_SUCCESS;
}

CMyFile::BOOL CMyFile::Close()
{
	if (m_pf)
	{
		fclose(m_pf);
		m_pf = nullptr;
	}
	return EXIT_SUCCESS;
}

void CMyFile::Seek(int size, Locate loc)
{
	fseek(m_pf, size, loc);
}

int CMyFile::TellSize()
{
	if (!m_pf)
		throw "Cannot get current location, because the file pointer is null!";
	return ftell(m_pf);
}

int CMyFile::GetSize()
{
	int size;
	Open(m_sFileName);
	Seek(0, LOC_END);
	size = TellSize();
	Seek(0, LOC_SET);
	return size;
}

int CMyFile::ReadFile(char *&sBuf, int size)
{
	if (!sBuf)
	{
		throw "Empty buffer!";
		return -1;
	}
/*
	if (!m_pf)
		throw ""
*/
	return fread(sBuf, sizeof(char), size, m_pf);
}

int CMyFile::WriteFile(const char *sBuf, int size)
{
	// 安全监测
	return fwrite(sBuf, sizeof(char), size, m_pf);
}

CMyFile::BOOL CMyFile::FindContent(const char *sContent)
{
	// 安全监测
	char buf[256];
	int pos = ftell(m_pf);
	int len = strlen(sContent);
	fread(buf, sizeof(char), len, m_pf);
	if (!strcmp(buf, sContent))
		return 1;

	// KMP
	while (EOF)
	{
		// 
	}

	Seek(pos, LOC_SET);
	return 0;
}

int CMyFile::ReadLine(char *&sBuf, int size/* = MAX_SIZE*/)
{
	int ret, sum = 0;
	char ch, *p = sBuf;
	sum += ret = fread(&ch, sizeof(char), 1, m_pf);
	while (ret > 0 && ch != '\n' && sum < size)
	{
		*p++ = ch;
		sum += ret = fread(&ch, sizeof(char), 1, m_pf);
	}

	if (ret <= 0)
		sum -= ret;

	return sum;
}

int CMyFile::WriteLine(const char *sBuf, int size/* = MAX_SIZE*/)
{
	return 0;
}
