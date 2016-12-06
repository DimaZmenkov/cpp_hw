// ConsoleApplication29.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
double det(double**a)
{double d=a[0][0]*a[1][1]*a[2][2]-a[2][0]*a[1][1]*a[0][2]-a[0][0]*a[2][1]*a[1][2];
d+=-a[2][2]*a[1][0]*a[0][1]+a[0][2]*a[1][0]*a[2][1]+a[2][0]*a[0][1]*a[1][2];
return d;
}

	int _tmain(int argc, _TCHAR* argv[])
{int n=3;



double**a=new double*[n];
for(int i=0;i<n;i++)
	a[i]=new double[n];
cout<<"Input matrix "<<endl;

	
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
	cin>>a[i][j];
cout<<endl;
cout<<det(a)<<endl;
return 0;
}