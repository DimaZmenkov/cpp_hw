

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
	String (const char*  str);
	 String(const String& rhs)
        : m_string(rhs.m_string)
        , m_refCounter(rhs.m_refCounter)
		, m_length(rhs.m_length)
    {
        (*m_refCounter)++;
    }

	~String()
	{
		  (*m_refCounter)--;

        if(*m_refCounter == 0)
        {
            if (m_string)
            {
                delete[] m_string;
               m_string  = nullptr;
            }
        }
    }
				
	size_t count() const
    {
        return *m_refCounter;
    }
	void set_elem(int pos, char c)
	{
	if(m_string [pos] != c)  *m_refCounter = 1;
		m_string [pos] = c;
	
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

	/*const char&  operator [](int pos) const
{
	return m_string [pos];
}*/
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
	//static char* staticCharArray[100];
//static int count;
//static bool flag;
//static size_t staticCountArray[100];
char*m_string;
int m_length;
 size_t* m_refCounter;

};
String:: String(const char* value)
        : m_string(new char[strlen(value)+1])
		, m_refCounter(new size_t(0))
        , m_length(strlen(value))
    {
        strcpy_s(m_string, m_length + 1, value);
        (*m_refCounter)++;
    }
	      
	 
	


 String& String::operator = ( const String& rhs)

 {
	m_string = rhs.m_string;
         m_refCounter = rhs.m_refCounter;
		m_length = rhs.m_length;
	(*m_refCounter)++;
	return *this;
 }

char*String::getString() const
{
	return m_string;
}
	
int _tmain(int argc, _TCHAR* argv[])
{
 
	 String s("abc");
    assert(s.count()==1);

    {
        String s2 = s;
        assert(s.count()==2);
        assert(s2.count()==2);
    }
	//=====
    assert(s.count()==1);

    String s3 = s;
    assert(s.count()==2);
    s3.set_elem(0, 'X');
    assert(s.count()==1);
    assert(s3.count()==1);
    
    
    cout << "PASSED" << endl;
	return 0;
}

























