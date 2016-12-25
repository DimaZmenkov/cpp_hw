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
	int  numberEncryption;
	const int size = 50;
	
	const int tableSize = 36;
	char str[size] ;
const char str1 [] = "abcdefghijklmnopqrstuvwxyz0123456789";
cout<<"Input  string"<<endl;
cin.getline(str,size);
	int length = strlen(str);
	
	for(int i = 0;i < length;i++)
    for(int j = 0;j < tableSize;j++)
if(str[i] == str1[j])
{ 
	numberEncryption = (j + 5) % tableSize;str[i] = str1[numberEncryption];break;
}
cout<<endl;
cout<<"new string"<<endl;
cout<<str<<endl;
return 0;
}