

#include "stdafx.h"
#include "iostream"
#include "cstring"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0, maxSize = 100;
char str[100];

cout<<"Input  string"<<endl;
cin.getline(str, maxSize);
cout<<endl; 
	int length = strlen(str);
	int* m = new int[length];
	int *m1 = new int[length];
	for(int i = 0; i < length;i++)
	{
		m[i] = 0;m1[i] = 0;
	}
	char* str1 = new char [length];
	for(int i = 0; i < length;i++)
		
		if(m[i] == 0) 
		{
			m1[count] = 1;m[i] = 1;str1[count] = str[i];
			
			for(int k = i + 1;k < length;k++)
				if(str[k] == str[i])
				{
					m[k] = 1;m1[count]++;
				}
		count++;
		}
	
		for(int i = 0; i < count;i++)
			cout<<str1[i]<<"    "<<m1[i]<<endl;
		cout<<endl; 
		cin>>count;
		delete[] m;
		m=0;
		delete[] m1;
		m1=0;
		delete[] str1;
		str1=0;
		return 0;
}
