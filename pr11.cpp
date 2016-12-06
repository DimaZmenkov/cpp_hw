// ConsoleApplication23.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"
using namespace std;

bool test(char c)
{for(char i='a';i<='z';i++)
		if (i==c) return true;
	for(char i='A';i<='Z';i++)
if (i==c) return true;
return false;}
int _tmain(int argc, _TCHAR* argv[])
{int pos,n=30;
char *s=new char[n];
cout<<"Input  string"<<endl;
cin.getline(s,n);
	int l=strlen(s);
	for(int i=0;i<l;i++)
	if (s[i]=='.') pos=i;
		
	if(test(s[0])) 
	{for(int i=0;i<pos;i++)
	s[i]=s[i+1];pos--;
	}
	for(int i=0;i<pos;i++)
	if((!test(s[i]))&&(test(s[i+1]))) 
		{for(int j=i+1;j<pos;j++)
		s[j]=s[j+1];pos--;
			cout<<endl;
	    }

cout<<"new string"<<endl;
for(int i=0;i<=pos;i++)
cout<<s[i];
}
