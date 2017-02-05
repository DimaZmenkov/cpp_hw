

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
#include <memory>
using namespace std;

class String 
{ 
	


public:
	String (const char*  str);
	 String(const String& rhs): 
		 m_string(rhs.m_string)
      ,   m_length(rhs.m_length)
    {
    }

	~String()
	{
	}
				
	size_t count() const
    {
        return m_string.use_count() ;   
    }
	void set_elem(int pos, char c)
	{
	char* temp = 
		 m_string.get();
				if( temp[pos] != c)
			{
				char*  string1 = new char[m_length + 1];
			strcpy_s(string1, m_length + 1, temp);
			string1[pos] = c;
	shared_ptr<char>(new char[m_length  + 1]);
		m_string.reset( string1);
				}
		
		
			
			//swap(*m_string, *temp);
			 
		
			
		   
	}
	
	
	 bool operator < (const  String & rhs)
	  {
		 size_t min, count = 0;
		char*  string1 = 
		 m_string.get();
		char*  string2 = 
		rhs.m_string.get();
		if(m_length < rhs.m_length) min =  m_length; else min = rhs.m_length;
		 for (int i = 0;i < m_length; i++)	
	{
		if (string1[i] > string2[i]) return false;
		 if (string1[i] ==  string2[i]) count++;
    }
	if((m_length >= rhs.m_length)&&(count == m_length)) return false;
		 return true;
	 
	 }
	 String& operator=(const char* value)
    {
		
		m_length = strlen(value) ;
	char* string1 = new char[strlen(value) + 1];
		strcpy_s(string1, m_length + 1, value);
		shared_ptr<char>(new char[strlen(value) + 1]);
		m_string.reset( string1);
		return *this;
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
	char* string1 = 
		 m_string.get();
	return string1[pos] ;
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
	
shared_ptr<char>m_string;
int m_length;


};
String:: String(const char* value)
        : 
	m_length(strlen(value))
    {
      char* string1 = new char[strlen(value) + 1];
		strcpy_s(string1, m_length + 1, value);
		
		 shared_ptr<char>(new char[strlen(value) + 1]);
		m_string.reset( string1);
		
	}
	      
	 
	


 String& String::operator = ( const String& rhs)

 {
	
	 
	 m_string = rhs.m_string;
        
		m_length = rhs.m_length;
	
	return *this;
 }

char*String::getString() const
{
char* string1 = m_string.get();
	return string1;
}
	
int _tmain(int argc, _TCHAR* argv[])
{
 
	 String s("abc");
    
	 cout<<s.count()<<endl;
	 
	assert(s.count()==1);

    {
        String s2 = s;
        assert(s.count()==2);
        assert(s2.count()==2);
    }
	
    assert(s.count()==1);

    String s3 = s;
    assert(s.count()==2);
     assert(s3.count()==2);
	
	 s3.set_elem(0, 'X');
    assert(s3.count()==1);
	 assert(s.count()==1);
    
    
   
    cout << "PASSED" << endl;
	return 0;
}

























