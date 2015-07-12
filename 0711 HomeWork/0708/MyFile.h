#pragma once

#include <string>
#include <cstdio>

class CMyFile
{
public:
	typedef int BOOL;
	static int MAX_SIZE;
	enum Mode
	{
		READ = 0x01,			// "r"
		WRITE = 0x02,			// "w"
		READ_AND_WRITE = 0x03,	// "a+" 相当于 "r" 与 "w" 的叠加，Mode::READ | Mode::WRITE = Mode::READ_AND_WRITE
		APPEND = 0x04,			// "a"
		BINARY = 0x08,
		TEXT = 0x10,
		READ_BINARY = 0x09,		// "rb"
		WRITE_BINARY = 0x0A,	// "wb"
		READ_AND_WRITE_BINARY = 0x0B
	};
	enum Locate
	{
		LOC_SET,
		LOC_CUR,
		LOC_END
	};
private:
	Mode m_eMode;				// 打开模式
	std::FILE *m_pf;			// 文件
	std::string m_sFileName;	// 文件名
	Locate m_eLoc;				// 文件位置
private:
	std::string GetMode();
public:
	CMyFile(std::string sFileName = "", Mode eMode = READ_AND_WRITE);
	~CMyFile();
	// 文件定位与打开关闭
	BOOL Open(std::string sFileName, Mode eMode = READ_AND_WRITE);
	BOOL Close();
	void Seek(int size, Locate loc = LOC_CUR);
	int TellSize();
	// 文件操作
	int GetSize();			// 算出文件占用字节大小后，自动回到文件开头位置
	int ReadFile(char *&sBuf, int size);
	int WriteFile(const char *sBuf, int size);
	BOOL FindContent(const char *sContent);
	int ReadLine(char *&sBuf, int size = MAX_SIZE);
	int WriteLine(const char *sBuf, int size = MAX_SIZE);
	// int Output(const char *sFormat, ...);
	// int Input(const char *sFormat, ...);
};

