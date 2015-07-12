#include <iostream>
#include "MyFile.h"
using namespace std;

int main()
{
	// https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=0&rsv_idx=1&tn=baidu&wd=fread%E8%AF%BB%E5%8F%96%E6%95%B4%E4%B8%AA%E6%96%87%E4%BB%B6&rsv_pq=8754dfb80001b63e&rsv_t=c574n%2Fz72pYpzE5f0f%2FylLNOq6TJd3JlFBH7hKz5AvsbPNDpMn79K%2BiwEio&rsv_enter=1&rsv_sug3=16&rsv_sug1=15&sug=fread%E8%AF%BB%E5%8F%96%E5%A4%A7%E6%96%87%E4%BB%B6&oq=fread%E8%AF%BB%E5%8F%96&rsv_n=1
	// fread 读取整个文件就会出错！
	char *buf;
	int len1, len2, ret1, ret2;
	CMyFile f1, f2, f3;
	f3.Open("福利.jpg", CMyFile::Mode::WRITE_BINARY);
	f1.Open("黑魔导女孩.jpg", CMyFile::Mode::READ_BINARY);
	f2.Open("虫儿飞乐谱.zip", CMyFile::Mode::READ_BINARY);
	len1 = f1.GetSize();
	buf = new char[len1];
	ret1 = f1.ReadFile(buf, len1);
	ret1 = f3.WriteFile(buf, len1);
	delete buf;
	len2 = f2.GetSize();
	buf = new char[len2];
	ret2 = f2.ReadFile(buf, len2);
	ret2 = f3.WriteFile(buf, len2);
	delete buf;
	f1.Close();
	f2.Close();
	f3.Close();
	return EXIT_FAILURE;
}
