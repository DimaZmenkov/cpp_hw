// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//
#include "cmath"
#include "stdafx.h"
#include "iostream"
using namespace std;

void test1(int c)
{
	int i,f,n;
	
	i=0;f=0;n=0;
	while(n<=c)
	{
		if (n==c){f=1; cout<<"yes"<<endl;}
	
	i++;n=pow(i,3);
	}
	 
	
	if (f==0) cout<<"no"<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{int n,a;
	cin>>n;
	test1(n);
	return 0;
	
}


