// ConsoleApplication24.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int temp = 0, size = 12;
cout<<"Input size of array"<<endl;
	cin>>size;
int *mArray = new int[size]();
cout<<"Input  array"<<endl;
for(int i = 0;i < size;i++)
	cin>>mArray[i];
	
for(int i = 0;i < size-1;i++)
			if(!(i&1)) {temp = mArray[i];mArray[i] = mArray[i + 1];mArray[i + 1] = temp;}
cout<<"new  array"<<endl;
for(int i = 0;i < size;i++)
cout<<mArray[i]<<" ";
	cout<<endl;
return 0;	
	    
}
