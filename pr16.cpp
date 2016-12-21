// ConsoleApplication29.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
double det(double**a)

{
	double determinant = a[0][0] * a[1][1] * a[2][2] - a[2][0] * a[1][1] * a[0][2] - a[0][0] * a[2][1] * a[1][2];
determinant += -a[2][2] * a[1][0] * a[0][1] + a[0][2] * a[1][0] * a[2][1] + a[2][0] * a[0][1] * a[1][2];
return determinant;
}

	int _tmain(int argc, _TCHAR* argv[])
   {
	int size = 3;
double**aArray = new double*[size];
for(int i = 0;i < size;i++)
	aArray[i] = new double[size];
cout<<"Input matrix "<<endl;

	
for(int i = 0;i < size;i++)
for(int j = 0;j < size;j++)
	cin>>aArray[i][j];
cout<<endl;
cout<<det(aArray)<<endl;
for (int i = 0; i < size; i++) 
{
  delete [] aArray[i];
}
delete [] aArray;
return 0;
}