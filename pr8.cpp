// ConsoleApplication20.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include "iostream"
#include "cstring"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{int t,n=10;
char s[]="545";
char s1[]="545";
cout<<"Input  string";
cin.getline(s,n);
	int l=strlen(s);
	int* m=new int[l];
	int *m1=new int[l];
	for(int i=0; i<l;i++)
	{m[i]=0;m1[i]=0;}
	t=0;
	for(int i=0; i<l;i++)
		
		if(m[i]==0) 
		{m1[t]=1;m[i]=1;s1[t]=s[i];
			
			for(int k=i+1;k<l;k++)
				if(s[k]==s[i])
				{m[k]=1;m1[t]++;}
		t++;}
	
		for(int i=0; i<t;i++)
			cout<<s1[i]<<"    "<<m1[i]<<endl;
}
