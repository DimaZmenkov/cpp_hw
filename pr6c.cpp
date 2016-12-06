// ConsoleApplication16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void test(int c)
{int k=c&(c-1);
	if(k==0) cout<<"yes"<<endl;
else cout<<"no"<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{int n;
	cin>>n;
	if (n==0) cout<<"no"<<endl;
	else 
	test(n);
	return 0;
}



