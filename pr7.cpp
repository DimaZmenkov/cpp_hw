// ConsoleApplication18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"

using namespace std;

char* concate (char str1[], char str2[])
{
	int length = strlen(str1) + strlen(str2) + 1;
   char*  str = new char[length]();
      
   for(int i = 0; i < length;i++)
	    if(i < strlen(str1)) str[i] = str1[i];
	     else str[i] = str2[i - strlen(str1)];
	str[length] = '\0';
	
	return str;
}


int _tmain(int argc, _TCHAR* argv[])
{int n = 80;
char str1[] = "545";
char str2[] = "11";

cout<<"Input first string"<<endl;
cin.getline(str1, n);
cout<<endl;
cout<<"Input second string"<<endl;
	cin.getline(str2, n);
	cout<<endl;
	int length = strlen(str1) + strlen(str2) + 1;
	char* str = concate(str1, str2);
	for(int i = 0; i < length;i++)
	cout<<str[i];
	cout<<endl;
	delete[] str;
	str = 0;
	return 0;
}
