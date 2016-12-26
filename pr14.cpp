#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
bool test1(char ch)

{
	return(ch >= 'a') && (ch <= 'z');
}

bool test2(char ch)

{
	return(ch >= 'A') && (ch <= 'Z');
}

bool test3(char ch)

{
	return(ch >= '1') && (ch <= '9')|| (ch == '0');
}

int _tmain(int argc, _TCHAR* argv[])
{const int sizePass = 8;
	const int sizeTable = 'z'-'a'+'Z'-'A'+3*('9'-'1') + 9;
int count0, count, count1,  flag1, count2, flag2, flag3;
	bool fs = false;
	bool flag = false, flag01;
	char pass[sizePass] ;
char ch;
	char table[sizeTable] ;
	ofstream fout;
	ifstream fin;
	fin.open("D:/file.txt");
	count = 0;
	for(char i = 'a';i <= 'z';i++)
	{
		table[count] = i; count++;
	}
	for(char i = 'A';i <= 'Z';i++)
	{
		table[count] = i; count++;
	}
	for(char i = '1';i <= '9';i++)
	for(int j = 0;j < 3;j++)
		{
			table[count] = i;count++;
	    }
		for(int j = 0;j < 3;j++)
		   {
			table[count] = '0'; count++;
		   }
			
		table[count] = '_'; 
			count = 0;
		
			while(fin>>ch)
		if(ch != '/n') count++;
		     
			fin.close();
			fin.open("D:/file.txt");
			 char *buff = new char[count + 8];
	for(int i = 0;i < count;i++)
		buff[i] = '0';    
		count = 0;
			while(fin>>ch)
		
			if(ch != '/n') 
			{
		buff[count] = ch;count++;
		    }           
		
		
		while( !flag )
		{
//obtain the password from the symbol table
			flag1 = 0;flag2 = 0;flag3 = 0;flag01 = false;
			for(int j = 0;j < sizePass;j++)
			
			{	
			count2 = rand() % sizeTable; pass[j] = table[count2];
				
			if(!flag01)
			        //password verification for compliance with .
						//Checks passwords characters until you have established a standard
			   // not necessarily check all password characters      
			{
				if(j > 2) if(flag1 + flag2 + flag3 == 3) flag01 = true;
				if(!flag01) if(test1(pass[j])) 
				
				{
					flag1 = 1;continue;
				}

		if(flag2 == 0) if(test2(pass[j])) 
		
		{
			flag2 = 1;continue;
		}

		if(flag3 == 0) if(test3(pass[j])) 
		
		{
			flag3 = 1;continue;
		}

			          }

		    }
		if(!flag01) continue;
			count1 = 0;
		flag = true;count0 = 0;
		//the password is checked against a list of passwords made earlier
		//passwords are compared to the first differing character
		while(count0 < count)

		{
			if(buff[count0] != pass[count1])
			      
			      {
				count0 += sizePass - count1;count1 = 0;
			      }

			else 
			
			{
				count1++;count0++;
			}

		if (count1 == 8)
		  
		  {
			flag = false;break;
		  }

		}
			
		}
	fin.close();
		cout<<"pass"<<endl;

		fout.open("D:/file.txt");
	for(int j = 0;j < sizePass;j++)
  { 
	  buff[count + j] = pass[j];cout<<pass[j]<<" ";
  }
 for(int j = 0;j < count +  sizePass ;j++)
	fout<<buff[j];
	fout.close();
	delete[] buff;
	return 0;
}