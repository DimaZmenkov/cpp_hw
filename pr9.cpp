// ConsoleApplication21.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{int t,k,n=10,d=36;
char *s=new char[n];
char *s1=new char[d];
cout<<"Input  string"<<endl;
cin.getline(s,n);
	int l=strlen(s);t=0;
	for(char i='a';i<='z';i++)
	{s1[t]=i;t++;}
	for(char i='0';i<='9';i++)
	{s1[t]=i;t++;}
	cout<<"table"<<endl;
	for(int j=0;j<d;j++)
		cout<<s1[j];
	for(int i=0;i<l;i++)
    for(int j=0;j<d;j++)
if(s[i]==s1[j])
{ k=(j+5)%d;s[i]=s1[k];break;}
cout<<endl;
cout<<"new string"<<endl;
cout<<s;
}