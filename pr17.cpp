// ConsoleApplication30.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
double** MatrixMultiply(double**a,double**b,int n ,int m ,int k)
{double**c=new double*[n];
for(int i=0;i<n;i++)
	c[i]=new double[k];
	for(int i=0;i<n;i++)
for(int j=0;j<k;j++)
{c[i][j]=0;
for(int f=0;f<m;f++)
	c[i][j]+=a[i][f]*b[f][j];}
	return c;
}

	int _tmain(int argc, _TCHAR* argv[])
{int n,m,k;

	cout<<"Input sizes of first matrix"<<endl;
	cin>>n>>m;
	cout<<"Input second size second matrix"<<endl;
	cin>>k;
	double**a=new double*[n];
for(int i=0;i<n;i++)
	a[i]=new double[m];
double**b=new double*[m];
for(int i=0;i<m;i++)
	b[i]=new double[k];
cout<<"Input  first matrix "<<endl;
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
	cin>>a[i][j];
cout<<endl;
cout<<"Input  second matrix "<<endl;
for(int i=0;i<m;i++)
for(int j=0;j<k;j++)
	cin>>b[i][j];
cout<<endl;
double**c=new double*[n];
for(int i=0;i<n;i++)
	c[i]=new double[k];
c=MatrixMultiply(a,b,n,m,k);
for(int i=0;i<m;i++)
{for(int j=0;j<k;j++)
cout<<c[i][j]<<" ";
	cout<<endl;
}
return 0;
	}