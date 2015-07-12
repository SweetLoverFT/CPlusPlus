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
		READ_AND_WRITE = 0x03,	// "a+" �൱�� "r" �� "w" �ĵ��ӣ�Mode::READ | Mode::WRITE = Mode::READ_AND_WRITE
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
	Mode m_eMode;				// ��ģʽ
	std::FILE *m_pf;			// �ļ�
	std::string m_sFileName;	// �ļ���
	Locate m_eLoc;				// �ļ�λ��
private:
	std::string GetMode();
public:
	CMyFile(std::string sFileName = "", Mode eMode = READ_AND_WRITE);
	~CMyFile();
	// �ļ���λ��򿪹ر�
	BOOL Open(std::string sFileName, Mode eMode = READ_AND_WRITE);
	BOOL Close();
	void Seek(int size, Locate loc = LOC_CUR);
	int TellSize();
	// �ļ�����
	int GetSize();			// ����ļ�ռ���ֽڴ�С���Զ��ص��ļ���ͷλ��
	int ReadFile(char *&sBuf, int size);
	int WriteFile(const char *sBuf, int size);
	BOOL FindContent(const char *sContent);
	int ReadLine(char *&sBuf, int size = MAX_SIZE);
	int WriteLine(const char *sBuf, int size = MAX_SIZE);
	// int Output(const char *sFormat, ...);
	// int Input(const char *sFormat, ...);
};

