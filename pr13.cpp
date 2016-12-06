// ConsoleApplication25.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{const int n=50;
	int* m=new int[n];
	int k,l=n;
	k=0;
	cout<<"old array"<<endl;
	for(int i=1;i<100;i++)
		if(i&1) {m[k]=i;cout<<m[k]<<" ";k++;}
		cout<<endl;
	cout<<"new array"<<endl;
		for(int i=0;i<n;i++)
	{k=rand()%l;
	cout<<m[k]<<" ";
for(int j=k;j<l-1;j++)
	m[j]=m[j+1];l--;
    }

return 0;
}

