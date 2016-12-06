// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void test(int c)
{
	if(c%2==0) cout<<"even";
	else cout<<"odd"
}

int _tmain(int argc, _TCHAR* argv[])
{int n;
	cin>>n;
	test(n);
	return 0;
}
