#include "HxxString.h"

int main()
{
	HxxString str1 = "hello";
	HxxString str2 = " hi!";
	HxxString str3 = str1 + str2;
	cout << str1 << "   " << str1.size() << endl;
	cout << str3 << "   " << str3.size() << endl;
	system("pause");
	return 0;
}