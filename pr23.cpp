
#include "stdafx.h"
  #include <cassert>  
#include <iostream>
     #include <cstring>
using namespace std;
   //https://ru.wikipedia.org/wiki/%D0%A0%D0%B8%D0%BC%D1%81%D0%BA%D0%B8%D0%B5_%D1%86%D0%B8%D1%84%D1%80%D1%8B
  // there are only six uses of "subtraction rule":
//    |V = 4
//    |X = 9
//    XL = 40
//    XC = 90
//    CD = 400
//    CM = 900


    
	class RomansNumber { 
    public:
	   
		
		RomansNumber(char* str)  
		{

	 m_arabian = ConvertToArabian(str);
	   
	   }
	RomansNumber()
	{
	}
	  
	RomansNumber(int arabian)
	{
	m_arabian = arabian;
	}
	RomansNumber& operator = (const RomansNumber& rhs)
	{
		if(& rhs != this)
		 m_arabian = rhs. m_arabian;
		return *this;
	}
	
		RomansNumber(const RomansNumber& rhs) 
	  { 
		  *this = rhs;
	  }
	~RomansNumber()
	   {
		   
	   }
	   
	   
	 static   int ConvertToArabian(char * m_number) 
	
	
	{
		bool flag = false;
		int length = strlen(m_number);
    char tableRomans[] = "|VXLCDM";
	int arabiansArray[]={1, 5, 10, 50, 100, 500, 1000};
	int count = 0;
	int sum = 0;
	while(count < length)
	{
		flag = false;
         for (int i = 0; i < 3; i++)
		  {
			 if (m_number[count] == tableRomans[2*i] )
			 for (int j = 0; j < 2; j++)
	 if (m_number[count + 1] == tableRomans[2*i + j + 1 ])
	           { 
			   flag = true; sum += arabiansArray[2*i + j + 1] - arabiansArray[2*i]; count += 2;break;
	           }
	           if (flag) break;
	     }
	if (flag) continue;
	 
	for (int i = 0; i < 7; i++)
		if (m_number[count] == tableRomans[i] ) 
		{
			sum += arabiansArray[i];
			//count++;
			break;
		}
	count++;
	}
	return sum;
	
	}
	
	   static char* ConvertToRomans(int number,int& rLength) 
	 {
		bool flag = false;
		char str[50]  ;
    char tableRomans[] = "|VXLCDM";
	int arabiansArray[]={1, 5, 10, 50, 100, 500, 1000};
	int count1 = 0, count = 6;
	int digit, sum = 0;
	int balance = number;
	
	
	while(balance > 0)
	{
		if( balance/arabiansArray[count] == 0) 
		{
			count--; continue;
		}
		  flag = false;
	 for (int i = 0; i < 3; i++)
		  {
			  for (int j = 0; j < 2; j++)
	 if ((count == 2*i + j)&& (balance >= arabiansArray[2*i + j + 1] - arabiansArray[2*i] ))
	           { 
			   flag = true; str[count1] = tableRomans[2*i] ;  
			   str[count1 + 1] = tableRomans[2*i + j + 1] ;count1 += 2;count -= j + 1;
			   balance -= arabiansArray[2*i + j + 1] - arabiansArray[2*i];
			   break;
	           }
	           if (flag) break;
	     }
	if (flag) continue;
	digit =  balance/arabiansArray[count];
	  for (int i = 0; i < digit; i++)
	        {
				str[count1++] = tableRomans[count];
		    }
	  
	    balance -= arabiansArray[count] * digit; count--;
	
	}
char*str1 =	new char[count1 + 1 ];
	for (int i = 0; i < count1; i++)
	     {
		str1[i] = str[i];
	     }
	str1[count1] = '\n';
	rLength = count1;
return str1;
            }

	   static char* ConvertToRomans(int number) 
	 {
		bool flag = false;
		char str[50]  ;
    char tableRomans[] = "|VXLCDM";
	int arabiansArray[]={1, 5, 10, 50, 100, 500, 1000};
	int count1 = 0, count = 6;
	int digit, sum = 0;
	int balance = number;
	
	
	while(balance > 0)
	{
		if( balance/arabiansArray[count] == 0) 
		{
			count--; continue;
		}
		  flag = false;
	 for (int i = 0; i < 3; i++)
		  {
			  for (int j = 0; j < 2; j++)
	 if ((count == 2*i + j)&& (balance >= arabiansArray[2*i + j + 1] - arabiansArray[2*i] ))
	           { 
			   flag = true; str[count1] = tableRomans[2*i] ;  
			   str[count1 + 1] = tableRomans[2*i + j + 1] ;count1 += 2;count -= j + 1;
			   balance -= arabiansArray[2*i + j + 1] - arabiansArray[2*i];
			   break;
	           }
	           if (flag) break;
	     }
	if (flag) continue;
	digit =  balance/arabiansArray[count];
	  for (int i = 0; i < digit; i++)
	        {
				str[count1++] = tableRomans[count];
		    }
	  
	    balance -= arabiansArray[count] * digit; count--;
	
	}
char*str1 =	new char[count1 + 1 ];
	for (int i = 0; i < count1; i++)
	     {
		str1[i] = str[i];
	     }
	str1[count1] = '\n';
	return str1;
            }
	   
	   
	   
	   RomansNumber operator + (const RomansNumber & rhs);
	RomansNumber& operator += (const RomansNumber & rhs);
	RomansNumber operator * (const RomansNumber & rhs);
	RomansNumber& operator *= (const RomansNumber & rhs);
	RomansNumber operator - (const RomansNumber & rhs);
	RomansNumber& operator -= (const RomansNumber & rhs);
	RomansNumber operator / (const RomansNumber & rhs);
	RomansNumber& operator /= (const RomansNumber & rhs);
	 bool operator == (const RomansNumber & rhs);
	 bool operator != (const RomansNumber & rhs);
	  bool operator < (const RomansNumber & rhs);
	   bool operator <= (const RomansNumber & rhs);
	   bool operator > (const RomansNumber & rhs);
	    bool operator >= (const RomansNumber & rhs);
	const	RomansNumber&  operator ++ ();
	const	RomansNumber  operator ++ (int);
	 const	RomansNumber&  operator -- ();
	 const	RomansNumber  operator -- (int);
		friend ostream& operator << (ostream& stream, const RomansNumber& rhs);
 // explicit  operator int() const
  //  {          without coomments compiler Visua Studio returned message:
	//	Ошибка	1	error C2071: RomansNumber::operator int: недопустимый класс хранения	c:\users\user\documents\visual studio 2012\projects\consoleapplication91\consoleapplication91\consoleapplication91.cpp	212	1	ConsoleApplication91

      
	//	return m_arabian;   
  //  } 
private:
		
	 int  m_arabian;
     };
     
	RomansNumber RomansNumber::operator + (const RomansNumber & rhs)
	{
      return  RomansNumber (m_arabian + rhs.m_arabian);
	}
   RomansNumber& RomansNumber::operator += (const RomansNumber & rhs)
	{
     return (*this = *this + rhs);
	}
    RomansNumber RomansNumber::operator * (const RomansNumber & rhs)
	{
     
	  return  RomansNumber (m_arabian * rhs.m_arabian);
	}
	RomansNumber&  RomansNumber::operator *= (const RomansNumber & rhs)
	{
     return *this = *this * rhs;
	}
	RomansNumber RomansNumber:: operator - (const RomansNumber & rhs)
	{
		return  RomansNumber (m_arabian - rhs.m_arabian);
	}
	 RomansNumber& RomansNumber::operator -= (const RomansNumber & rhs)
		 {
     return *this = *this - rhs;
	}
	RomansNumber  RomansNumber::operator / (const RomansNumber & rhs)
		{
			return  RomansNumber (m_arabian / rhs.m_arabian);
	}
	RomansNumber& RomansNumber::operator /= (const RomansNumber & rhs)
		 {
     return *this = *this / rhs;
	}
	 bool RomansNumber::operator == (const RomansNumber & rhs)
	 {
		 return rhs.m_arabian == m_arabian;
	 }
	  bool RomansNumber::operator != (const RomansNumber & rhs)
	  {
		  return !(*this == rhs);
	  }

	  bool RomansNumber::operator < (const RomansNumber & rhs)
	  {
		  return m_arabian < rhs.m_arabian;
	  }
	   bool RomansNumber::operator <= (const RomansNumber & rhs)
	   {
	   return((*this == rhs)||(*this < rhs));
	   }
	    bool RomansNumber::operator > (const RomansNumber & rhs)
		{
			 return !(*this <= rhs);
		}
	  bool RomansNumber::operator >= (const RomansNumber & rhs)
	  {
	    return !(*this < rhs);
	  }
		 const RomansNumber&  RomansNumber::operator++()
		{
			++m_arabian;
           return *this ;
		}
		const RomansNumber  RomansNumber::operator++(int)
		{
		    RomansNumber tmp(*this);
			++m_arabian;
		return tmp;
		}
	 const	RomansNumber&  RomansNumber::operator -- ()
		{
			--m_arabian;
           return *this ;
		}
	 const	RomansNumber  RomansNumber::operator -- (int)
		{
		    RomansNumber tmp(*this);
			++m_arabian;
		return tmp;
		}
		
		ostream& operator<<(ostream& stream, const RomansNumber& rhs)
   {
	   int length = 1;
	   
	 char*str = RomansNumber::ConvertToRomans(rhs.m_arabian, length);
	   
	 for (int i = 0;i <length ;i++)
      stream << str[i];
      return stream ;
   }
    
		int _tmain(int argc, _TCHAR* argv[])
   
	{
	
		 //https://ru.wikipedia.org/wiki/%D0%A0%D0%B8%D0%BC%D1%81%D0%BA%D0%B8%D0%B5_%D1%86%D0%B8%D1%84%D1%80%D1%8B
  // there are only six uses of "subtraction rule":
//    |V = 4
//    |X = 9
//    XL = 40
//    XC = 90
//    CD = 400
//    CM = 900
       
		RomansNumber r("MM|");
	    
		RomansNumber r1("MMV");
		cout<<r.ConvertToArabian("XX|X")<<endl; 
		  int  length = 1;
		char *str = r.ConvertToRomans(3999, length);
    
		for (int i = 0; i < length; i++)
		
		   cout<< str[i];
    cout<<endl; 
	RomansNumber r2 =r1+r;
	   r1 =r++;
	   cout<<r1<<endl;
	   cout<<r<<endl;
	   //assert(r <= r1);
	
	   return 0;
	
		
		}


