

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
	int* mArray = new int[length];
	int *m1Array = new int[length];
	for(int i = 0; i < length;i++)
	{
		mArray[i] = 0;m1Array[i] = 0;
	}
	char* str1 = new char [length];
	for(int i = 0; i < length;i++)
		
		if(mArray[i] == 0) 
		{
			m1Array[count] = 1;mArray[i] = 1;str1[count] = str[i];
			
			for(int k = i + 1;k < length;k++)
				if(str[k] == str[i])
				{
					mArray[k] = 1;m1Array[count]++;
				}
		count++;
		}
	
		for(int i = 0; i < count;i++)
			cout<<str1[i]<<"    "<<m1Array[i]<<endl;
		cout<<endl; 
		cin>>count;
		delete[] mArray;
		//mArray=0;
		delete[] m1Array;
		//m1Array=0;
		delete[] str1;
		//str1=0;
		return 0;
}
