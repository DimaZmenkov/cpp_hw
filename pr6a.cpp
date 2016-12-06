// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void test(int c)
{int i,f,k;
k=1;f=0;
	for(i=0;i<32;i++)
		{
	if(k==c) {f=1;cout<<"yes"<<endl;break;}
	 k=k<<1;  
	}
	if(f==0) cout<<"no"<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{int n;
	cin>>n;
	if (n==0) cout<<"no"<<endl;
	else 
	test(n);
	return 0;
}

