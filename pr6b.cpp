// ConsoleApplication9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int i,n,k,t;
int test()
{if(t==32) return 0;
	if(k==n) {cout<<"yes"<<endl;return 0;}
k=k<<1;t++;test();
}


int _tmain(int argc, _TCHAR* argv[])
{k=1;t=0;
	cin>>n;test();if(t==32) cout<<"no";
}

