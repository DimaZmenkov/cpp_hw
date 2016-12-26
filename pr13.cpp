// ConsoleApplication25.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	const int  size = 50;
	int mArray [size];
	int pos1 = 0, pos2 ;
	cout<<"old array"<<endl;
	for(int i = 1;i < 100;i++)
		if(i & 1) {mArray[pos1] = i;cout<<mArray[pos1]<<" ";pos1++;}
		 cout<<endl;
	cout<<"new array"<<endl;
		int quantityPermutation = 35 + rand() % 25;
	int temp = 0;
		for(int i = 0;i < quantityPermutation;i++)
	{
		pos1 = rand() % size;pos2 = rand() % size;
	if(pos1 != pos2) 
	
	    { 
		temp = mArray[pos1];mArray[pos1] = mArray[pos2];mArray[pos2] = temp;
	    }
	
	}

 cout<<"new array"<<endl;
 for(int i = 0;i < size;i++)
	  cout<<mArray[i]<<" ";
	 cout<<endl;
 return 0;
}

