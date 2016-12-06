// ConsoleApplication36.cpp: определяет точку входа для консольного приложения.
//
//#include "cassert"
#include "stdafx.h"
#include "iostream"
using namespace std;
int k;
	int*  map (int* a,int n)
	{for(int i=0;i<n;i++)
	      a[i]+=5;
	return a;
	}
	  int* filter (int *a,int n)
	{int t;
	k=0;	
	int *b=new int[n];
	for(int i=0;i<n;i++)
		if(a[i]>10){ b[k]=a[i];k++;}
	int*c=new int[k];
		for(int i=0;i<k;i++)
	c[i]=b[i];
	delete[] b;
		b=0;
	return c;
	}
	int reduce (int*a,int n)
	{int k;
	int b=a[0];
	for(int i=1;i<n;i++)
	b+=a[i]+2*b;
	return b;
	}
int _tmain(int argc, _TCHAR* argv[])
{int  n,t;
 int* (*pf) (int *,int );
  int (*pf1) (int *,int );
cout<<"Input quantity elements of array"<<endl;
cin>>n;
	int*a=new int[n];
	cout<<"Input  array"<<endl;
for(int i=0;i<n;i++)	
	cin>>a[i];
pf=map;
a=pf(a,n);
cout<<"  array after map"<<endl;
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
pf=filter;
int* b=(*pf)(a,n);
cout<<"  array after filter"<<endl;
for(int i=0;i<k;i++)
cout<<b[i]<<" ";
cout<<endl;
delete[] a;
a=0;
pf1=reduce;
t=pf1 (b, k);
cout<<"  value after reduce"<<endl;
cout<<t<<endl;

return 0;
}

