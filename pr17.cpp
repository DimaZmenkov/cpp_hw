

#include "stdafx.h"
#include "iostream"

using namespace std;
double** MatrixMultiply(double**aArray, double**bArray, int nSize, int mSize, int kSize)

{
	double**cArray = new double*[nSize];
for(int i = 0;i < nSize;i++)
	cArray[i] = new double[kSize];
	for(int i = 0;i < nSize;i++)
for(int j = 0;j < kSize;j++)
{
	cArray[i][j] = 0;
for(int f = 0;f < mSize;f++)
	cArray[i][j] += aArray[i][f] * bArray[f][j];}
	return cArray;
}

	int _tmain(int argc, _TCHAR* argv[])

	{
	int nSize, mSize, kSize;

	cout<<"Input sizes of first matrix"<<endl;
	cin>>nSize>>mSize;
	cout<<"Input second size second matrix"<<endl;
	cin>>kSize;
	double**aArray=new double*[nSize];
for(int i = 0;i < nSize;i++)
	aArray[i] = new double[mSize];
double**bArray = new double*[mSize];
for(int i = 0;i < mSize;i++)
	bArray[i] = new double[kSize];
cout<<"Input  first matrix "<<endl;
for(int i = 0;i < nSize;i++)
for(int j = 0;j < mSize;j++)
	cin>>aArray[i][j];
cout<<endl;
cout<<"Input  second matrix "<<endl;
for(int i = 0;i < mSize;i++)
for(int j = 0;j < kSize;j++)
	cin>>bArray[i][j];
cout<<endl;
//double**cArray = new double*[nSize];
//for(int i = 0;i < nSize;i++)
	//cArray[i] = new double[kSize];
double**cArray = MatrixMultiply(aArray, bArray, nSize, mSize, kSize);
for(int i = 0;i < mSize;i++)
{
	for(int j = 0;j < kSize;j++)
cout<<cArray[i][j]<<" ";
	cout<<endl;
}

for (int i = 0; i < nSize; i++) 
{
  delete [] aArray[i];
}
delete [] aArray;

for (int i = 0; i < mSize; i++) 
{
  delete [] bArray[i];
}
delete [] bArray;


for (int i = 0; i < nSize; i++) 
{
  delete [] cArray[i];
}
delete [] cArray;
	return 0;
	}