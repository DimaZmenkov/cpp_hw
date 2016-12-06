// ConsoleApplication32.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
bool test1(char c)
{for(char i='a';i<='z';i++)
		if (i==c) return true;
	return false;}
bool test2(char c)
{for(char i='A';i<='Z';i++)
		if (i==c) return true;
	return false;}
bool test3(char c)
{if (c==0) return true;
	for(char i='1';i<='9';i++)
		if (i==c) return true;
	return false;}
int _tmain(int argc, _TCHAR* argv[])
{const int n=8;
	int i,k,k1,ff,f1,k2,f2,f3,ff1=0;
	bool fs=false;
char* pass=new char[n];
char ch;
	char* t=new char[83];
	ofstream fout;
	ifstream fin;
	fin.open("D:/file.txt");
	k=0;
	for(char i='a';i<='z';i++)
	{t[k]=i; k++;}
	for(char i='A';i<='Z';i++)
	{t[k]=i; k++;}
	for(char i='1';i<='9';i++)
	for(int j=0;j<3;j++)
		{t[k]=i; k++;}
		for(int j=0;j<3;j++)
		{t[k]='0'; k++;}
			
		t[k]='_'; 
			k=0;
		
			while(fin>>ch)
		if(ch!='/n') k++;
		     
			fin.close();
			fin.open("D:/file.txt");
			 char *buff=new char[k+8];
	for(int i=0;i<k;i++)
		buff[i]='0';    
		k=0;
			while(fin>>ch)
		{if(ch!='/n') {
		buff[k]=ch;k++;
		              }           
		} 
		 ff=0;
		while(ff==0 )
		{
			f1=0;f2=0;f3=0;ff1=0;
			for(int j=0;j<n;j++)
			{	k2=rand()%83; pass[j]=t[k2];
				
			if(ff1==0){if(j>2) if(f1+f2+f3==3) ff1=1;
				if(f1==0) if(test1(pass[j])) {f1=1;continue;}
		if(f2==0) if(test2(pass[j])) {f2=1;continue;}
		if(f3==0) if(test3(pass[j])) {f3=1;continue;}
			          }
		    }
		if(ff1==0) continue;
			k1=0;
		ff=1;i=0;
		while(i<k)

		{if(buff[i]!=pass[k1]){i+=n-k1;k1=0;}
			else {k1++;i++;}
		if (k1==8) {ff=0;break;}
		}
			
		}
	fin.close();
		cout<<"pass"<<endl;
  
		fout.open("D:/file.txt");
	for(int j=0;j<n;j++)
  {buff[k+j]=pass[j];cout<<pass[j]<<" ";}
 for(int j=0;j<k+n;j++)
	fout<<buff[j];
	fout.close();
return 0;
}