// ConsoleApplication82.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication49.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication48.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include "iostream"

#include "cstring"

using namespace std;

class String 
{ 
	
public:
	String ( char*  str);
	~String()
	{
         for (int i = 0;i < count; i++)	
			 if (m_string == staticCharArray[i])
			 {
                     if(--staticCountArray[i]==0) delete[] staticCharArray[i]; 
			 }
	}
	//inline int GetLength() const;
	String& operator = (const String& rhs);
	char* getString() const; 


private:
	static char* staticCharArray[100];
static int count;
static bool flag;
static int staticCountArray[100];
char*m_string;
//int m_length;
};
String::String ( char *  str)

	
//m_length(strlen(str))
{
	bool flag = false;
	for (int i = 0;i < count; i++)	
	  if (strcmp (str, staticCharArray[i] )==0)
		  {
			  str = staticCharArray[i];staticCountArray[i]++; flag = true;break;
	      }
			  
	      
	 if (!flag)
	  {
		  staticCharArray[count] = str; staticCountArray[count++]++;
	  }	   
	
}

String& String::operator = (const String& rhs)
{
	if(this == &rhs) 
		return *this;
	for (int i = 0;i < count; i++)	
	 // if (strcmp (rhs.m_string, staticCharArray[i] )==0)
		  if (rhs.m_string == staticCharArray[i]) 
		  {
			  m_string = staticCharArray[i];staticCountArray[i]++; return *this;
	      }
//return *this;

}

char*String::getString() const
{
	return m_string;
}
	/*int String::getLength() const
 {
	 return m_length;
}*/
char* String::  staticCharArray[100];
int String:: count;
bool String:: flag;
int String:: staticCountArray[100];
int _tmain(int argc, _TCHAR* argv[])
{
 String str1("123");
	String str2 = str1;
	

	return 0;
}

