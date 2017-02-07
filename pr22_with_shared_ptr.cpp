

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
#include <type_traits>

using namespace std;

class String 
{ 
	


public:
	String (const char*  str);
	 String(const String& rhs): 
		 m_string(rhs.m_string)
      //,   m_length(rhs.m_length)
    {
    }

	~String()
	{
	}
				
	size_t count() const
    {
        return m_string.use_count() ;   
    }
	/*void set_elem(int pos, char c)
	{
	char* temp = 
		 m_string.get();
				if( temp[pos] != c)
			{
				char*  string1 = new char[m_length + 1];
			swap(*string1, *temp);
				//strcpy_s(string1, m_length + 1, temp);
			string1[pos] = c;
	shared_ptr<char>(new char[m_length  + 1]);
		m_string.reset( string1);
				}
		
		
			
			//swap(*m_string, *temp);
			 
		
			
		   
	}*/
	
	void set_elem(int pos, char c)
    {
        if( m_string.get()[pos] != c)
        {
            String(m_string.get()).swap(*this);
            m_string.get()[pos] = c;
        }
    }



    void swap (String& rhs) //noexcept 
		//Ошибка	1	error C3646: noexcept: неизвестный спецификатор переопределения	
//c:\users\user\documents\visual studio 2012\projects\consoleapplication143\
//consoleapplication143\consoleapplication143.cpp	87	1	ConsoleApplication143

    {
        ::swap(m_string, rhs.m_string);
      // ::swap(m_length, rhs.m_length);
    }
	 bool operator < (const  String & rhs)
	  {
		 
	 return strcmp(m_string.get(), rhs.m_string.get()) < 0; 
	 }
	 String& operator=(const char* value)
    {
		if(strcmp(m_string.get(), value) != 0)
		//m_length = strlen(value) ;
	      String(value).swap(*this);
		
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
	//char* string1 = 
		// m_string.get();
	//return string1[pos] ;
	return m_string.get()[pos] ;
	}
	
	friend ostream& operator<<(ostream& stream, const String & rhs)
   {
	  
	   if(rhs.m_string)
	  for (int i = 0;i <strlen(rhs.m_string.get()) ; i++)
			  stream << rhs[i];
	   else cout <<"string is not exist"<< endl; 

	   return stream ;
   }
private:
	
shared_ptr<char>m_string;
//int m_length;


};
String:: String(const char* value)
	//: 
	//m_length(strlen(value))
    {
      char* string1 = new char[strlen(value) + 1];
		strcpy_s(string1,strlen(value) + 1, value);
		
		 shared_ptr<char>(new char[strlen(value) + 1]);
		m_string.reset( string1);
		
	}
	  
	


 String& String::operator = ( const String& rhs)

 {
	
	 
	 m_string = rhs.m_string;
        
		//m_length = rhs.m_length;
	
	return *this;
 }

char*String::getString() const
{
//char* string1 = m_string.get();
	//return string1;
return m_string.get();
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

























