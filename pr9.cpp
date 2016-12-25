// ConsoleApplication25.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication21.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])

{
	int count, numberEncryption, size = 10;
const int tableSize = 36;

char str1 [tableSize];
cout<<"Input  size of string"<<endl;
cin>>size;
char *str = new char[size];
cout<<"Input  string"<<endl;
cin.getline(str,size);
	int length = strlen(str);count=0;
	for(char i = 'a';i <= 'z';i++)
	{
		str1[count] = i;count++;}
	for(char i = '0';i <= '9';i++)
	{
		str1[count] = i;count++;}
	cout<<"table"<<endl;
	for(int j = 0;j < tableSize;j++)
		cout<<str1[j];
	for(int i = 0;i < length;i++)
    for(int j = 0;j < tableSize;j++)
if(str[i] == str1[j])
{ 
	numberEncryption = (j + 5) % tableSize;str[i] = str1[numberEncryption];break;
}
cout<<endl;
cout<<"new string"<<endl;
cout<<str;
delete[] str;
return 0;
}