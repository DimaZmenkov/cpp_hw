

#include "stdafx.h"
#include "iostream"
#include "cstring"

using namespace std;
bool test(char ch)
   
{
	return(ch >= 'a') && (ch <= 'z');
}

bool test1(char ch)

{
	return(ch >= 'a')&&(ch <= 'z')||(ch >= 'A')&&(ch <= 'Z');
}

int toupper ( int c )

{return c+'A' - 'a';
}

int _tmain(int argc, _TCHAR* argv[])
{int maxSize = 30;
char *str = new char[maxSize];

cout<<"Input  string"<<endl;
cin.getline(str, maxSize);
	
	int length = strlen(str);
	if(test(str[0])) str[0] =  toupper(str[0]) ;
	for(int i=0;i<length-1;i++)
	if((!test1(str[i]))&&(test(str[i+1]))) str[i+1] = toupper(str[i+1]) ;
		cout<<endl;

		cout<<"new string"<<endl;
       cout<<str<<endl;

delete[] str;

}