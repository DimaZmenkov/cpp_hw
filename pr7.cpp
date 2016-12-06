// ConsoleApplication18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"
using namespace std;

char* concate (char s1[],char s2[])
{int l=strlen(s1)+strlen(s2);
char*  s = new char[l]();
for(int i=0; i<l;i++)
	if(i<strlen(s1)) s[i]=s1[i];
	else s[i]=s2[i-strlen(s1)];
	
return s;}


int _tmain(int argc, _TCHAR* argv[])
{int n=10;
char s1[]="545";
char s2[]="11";

cout<<"Input first string";
cin.getline(s1,n);
cout<<"Input second string";
	cin.getline(s2,n);
	int l=strlen(s1)+strlen(s2);
	char* s=concate(s1,s2);
	for(int i=0; i<l;i++)
	cout<<s[i];

}
