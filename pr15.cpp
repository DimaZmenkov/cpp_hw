// ConsoleApplication27.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{int n,m;
cout<<"Input n i m"<<endl;
cin>>n>>m;
int**a=new int*[n];
for(int i=0;i<n;i++)
	a[i]=new int[m];
int**a1=new int*[m];
for(int i=0;i<m;i++)
	a1[i]=new int[n];
	cout<<"Input array"<<endl;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
	cin>>a[i][j];
cout<<endl;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
	a1[j][n-i-1]=a[i][j];
for(int i=0;i<m;i++)
{for(int j=0;j<n;j++)
	cout<<a1[i][j]<<" ";
cout<<endl;
}
return 0;
}

