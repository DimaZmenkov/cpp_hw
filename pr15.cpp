// ConsoleApplication27.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])

{
	int n,m;

	cout<<"Input n i m"<<endl;
cin>>n>>m;

int**aArray = new int*[n];

for(int i = 0;i < n;i++)
	aArray[i] = new int[m];

int**a1Array = new int*[m];
for(int i = 0;i < m;i++)
	a1Array[i] = new int[n];
	
cout<<"Input array"<<endl;
for(int i = 0;i < n;i++)
for(int j = 0;j < m;j++)
	cin>>aArray[i][j];

cout<<endl;
for(int i = 0;i < n;i++)
for(int j = 0;j < m;j++)
	a1Array[j][n - i - 1] = aArray[i][j];

for(int i = 0;i < m;i++)
{
	for(int j = 0;j < n;j++)
	cout<<a1Array[i][j]<<" ";
cout<<endl;
}

for (int i = 0; i < n; i++) 
{
  delete [] aArray[i];
}
delete [] aArray;

for (int i = 0; i < m; i++)
{
  delete [] a1Array[i];
}
delete [] a1Array;

return 0;

}

