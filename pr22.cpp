// ConsoleApplication82.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication49.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication48.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication82.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication49.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication48.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <cstring>

using namespace std;

class String 
{ 
	


public:
	String ( char*  str);
	~String()
	{
		//(*m_refCounter)--;
		//if(	* m_refCounter  == 0) 
	
						 //delete[] staticCharArray[i]; 
			  for (int i = 0;i < count; i++)	
			  if(staticCountArray[i] > 0)
				 if(m_string == staticCharArray[i])
			   {
				   
                     if(--staticCountArray[i]==0)
					if( m_string)
	{
	delete[]  m_string;
	   m_string =  0;
		}
				break;		 
				 }			 /*{ 
							 
							 
							 for (int j = i;j < count - 1; j++)
			{ 
				staticCharArray[j] = staticCharArray[j + 1];
			 staticCountArray[j] = staticCountArray[j + 1];
			}
			 count--;   
					 }*/
			  // }

	}
	//inline int GetLength() const;
	
	 bool operator < (const  String & rhs)
	  {
		 size_t min, count = 0;
		 if(m_length < rhs.m_length) min =  m_length; else min = rhs.m_length;
		 for (int i = 0;i < m_length; i++)	
	{
		if (m_string[i] >  rhs.m_string[i]) return false;
		 if (m_string[i] ==  rhs.m_string[i]) count++;
    }
	if((m_length >= rhs.m_length)&&(count == m_length)) return false;
		 return true;
	 
	 }
	 
	  bool operator == (const  String & rhs)
	  {
         return m_string == rhs.m_string;
	  }
	 bool operator <= (const String  & rhs)
	   {
	   return((*this == rhs)||(*this < rhs));
	   }
	 bool operator > (const String & rhs)
		{
			 return !(*this <= rhs);
		}
	  bool operator >= (const String & rhs)
	  {
	    return !(*this < rhs);
	  }
	 String& operator = (const String& rhs);
	char* getString() const; 

	const char&  operator [](int pos) const
{
	return m_string [pos];
}
	friend ostream& operator<<(ostream& stream, const String & rhs)
   {
	  
	   if(rhs.m_string)
	  for (int i = 0;i <rhs.m_length ; i++)
			  stream << rhs[i];
	   else cout <<"string is not exist"<< endl; 

	   return stream ;
   }
private:
	static char* staticCharArray[100];
static int count;
static bool flag;
static size_t staticCountArray[100];
char*m_string;
int m_length;
 size_t* m_refCounter;

};
String::String ( char *  str):

	//m_string(new char[strlen(str)+1]),
m_length(strlen(str))
{
	bool flag = false;
	for (int i = 0;i < count; i++)	
	  if(staticCountArray[i] > 0) 
		  if (strcmp (str, staticCharArray[i] )==0)
		  { 
			  m_refCounter = &staticCountArray[i];
			 m_string  = staticCharArray[i];
			// (* m_refCounter)++;
			 staticCountArray[i]++; 
			 flag = true;break;
	      }
			  
	      
	 if (!flag)
	  {
		  m_string= new char[strlen(str)+1];
		 // staticCharArray[count]= new char[m_length];
		  strcpy_s(m_string, m_length + 1, str);
		  staticCharArray[count] = m_string ; 
		 // m_string = staticCharArray[count];
		  m_refCounter = &staticCountArray[count];
		  staticCountArray[count++]++;
	  //count++;
	 }	   
	
}

String& String::operator = (const String& rhs)
{
	int pos;
	if((this == &rhs) ||(rhs.m_string == m_string))
		return *this;
	
	for (int i = 0;i < count; i++)
	 if(staticCountArray[i] > 0)
		if( m_string == staticCharArray[i])
	{
		staticCountArray[i]--;pos = i;break;
	}
	//(* m_refCounter)--;
		if(	* m_refCounter  == 0) 
	if( m_string)
		
		
		delete[] m_string;
	 /*for (int j = pos;j < count - 1; j++)
			{ 
				staticCharArray[j] = staticCharArray[j + 1];
			 staticCountArray[j] = staticCountArray[j + 1];
			}
	 count--;*/
	 
	for (int i = 0;i < count; i++)	
	 // if (strcmp (rhs.m_string, staticCharArray[i] )==0)
		   if(staticCountArray[i] > 0)
		 if (rhs.m_string == staticCharArray[i]) 
		{ 
			m_string = staticCharArray[i];staticCountArray[i]++; 
	m_refCounter = &staticCountArray[i];
			break;
	      }
		
	
return *this;
}

char*String::getString() const
{
	return m_string;
}
	/*int String::getLength() const
 {
	 return m_length;
}*/
char* String::staticCharArray[100];
int String:: count;
bool String::flag;
size_t String::staticCountArray[100];
int _tmain(int argc, _TCHAR* argv[])
{
 String str1("123");
	String str2("111");
	str2= str1;
	String str3("124");
	String str4("126");
	String str5("1231");
	str3 =str1;
	//for (int i = 0;i < str1.count; i++)	
	//cout<<str1.staticCountArray[i]<<endl;
		cout<<str3[2]<<endl;
assert(str2 == str1);
assert(str3 < str4);
	assert(str4 > str3);
	assert(str4 > str3);
	assert(str3 < str5);
	
	cout << str3<<endl;
	char* str = new char[3];
String s(str);
delete str;
cout <<s<< endl; //???
	
	return 0;
}


