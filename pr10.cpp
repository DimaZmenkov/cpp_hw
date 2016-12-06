// ConsoleApplication22.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"
using namespace std;
bool test(char c)
{for(char i='a';i<='z';i++)
		if (i==c) return true;
	return false;}
bool test1(char c)
{for(char i='a';i<='z';i++)
		if (i==c) return true;
	for(char i='A';i<='Z';i++)
if (i==c) return true;
return false;}
int _tmain(int argc, _TCHAR* argv[])
{int n=30;
char *s=new char[n];
cout<<"Input  string"<<endl;
cin.getline(s,n);
	int l=strlen(s);
	if(test(s[0])) s[0]-=32;
	for(int i=0;i<l-1;i++)
	if((!test1(s[i]))&&(test(s[i+1]))) s[i+1]-=32;
		cout<<endl;
cout<<"new string"<<endl;
cout<<s;
}