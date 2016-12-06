// ConsoleApplication24.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{int b,l,n=12;
int *m=new int[n];
cout<<"Input  quantity of elements"<<endl;
cin>>l;
cout<<"Input  array"<<endl;
for(int i=0;i<l;i++)
	cin>>m[i];
	for(int i=0;i<l-1;i++)
			if(!(i&1)) {b=m[i];m[i]=m[i+1];m[i+1]=b;}
cout<<"new  array"<<endl;
for(int i=0;i<l;i++)
cout<<m[i];
		
	    
}
