// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int sum(int c)
{int k,n,s;
s=c%10;n=c/10;k=n%10;s+=k;n/=10;k=n%10;s+=k;
return s;

}


int _tmain(int argc, _TCHAR* argv[])
{int n;
	cin>>n;
	cout<<sum(n)<<endl;
	return 0;
}
