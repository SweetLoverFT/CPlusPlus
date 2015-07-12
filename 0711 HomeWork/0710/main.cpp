#include <iostream>
#include "MyDate.h"
#include "MyArray.h"

using namespace std;

int main()
{
	CMyDate date(2014, 11, 10);
	CMyArray arr(10);
	date += 485;
	date.Print();
	cin >> arr;
	cout << arr[5] << endl;
	return EXIT_SUCCESS;
}
