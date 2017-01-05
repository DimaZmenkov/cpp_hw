
#include "stdafx.h"
  #include <cassert>  
#include <iostream>
     #include <cstring>
using namespace std;
   //https://ru.wikipedia.org/wiki/%D0%A0%D0%B8%D0%BC%D1%81%D0%BA%D0%B8%D0%B5_%D1%86%D0%B8%D1%84%D1%80%D1%8B
  // there are only six uses of "subtraction rule":
//    IV = 4
//    |X = 9
//    XL = 40
//    XC = 90
//    CD = 400
//    CM = 900

 
    
	class RomansNumber { 
    public:
	   
		
		RomansNumber(const char* str)  
		{

	 m_arabian = ConvertToArabian(str);
	  
		}
	RomansNumber()
	{
		
	}
	  
	RomansNumber(int arabian):
m_arabian(arabian)
	{
		
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
	   
	   
	 static   int ConvertToArabian(const char * m_number) 
	
	
	{
		bool flag = false;
		int length = strlen(m_number);
  
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
	
	   static void ConvertToRomans(int number, int& rLength, char*& paramArray) 
	 {
		bool flag = false;
		char str[50]  ;
  
	
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
//char*str1 =	new char[count1 + 1 ];
	for (int i = 0; i < count1; i++)
	     {
		paramArray[i] = str[i];
	     }
	paramArray[count1] = '\n';
	rLength = count1;
//return str1;
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
		
	 
	 
	 //ostream& operator << (ostream& stream, const RomansNumber& rhs)
	// without coomments compiler Visua Studio returned message:
		 //{  	5	IntelliSense: слишком много параметров для этой функции оператора	c:\Users\User\Documents\Visual Studio 2012\Projects\ConsoleApplication93\ConsoleApplication93\ConsoleApplication93.cpp	225	12	ConsoleApplication93

	   //int length = 1;
	   //char*str = RomansNumber::ConvertToRomans(rhs.m_arabian, length);
	   //for (int i = 0;i <length ;i++)
      //stream << str[i];
      //return stream ;
		//}
		
	 
	 
	 
	 // explicit  operator int() const
  //  {          without coomments compiler Visua Studio returned message:
	//	Ошибка	1	error C2071: RomansNumber::operator int: недопустимый класс хранения	c:\users\user\documents\visual studio 2012\projects\consoleapplication91\consoleapplication91\consoleapplication91.cpp	212	1	ConsoleApplication91

      
	//	return m_arabian;   
  //  } 
private:
		static const char tableRomans[8]  ;
	static const int arabiansArray[7];
	 int  m_arabian;
    
};
     
const char RomansNumber::tableRomans[] = "IVXLCDM";
	 const int RomansNumber::arabiansArray[] = {1, 5, 10, 50, 100, 500, 1000};
	RomansNumber RomansNumber::operator + (const RomansNumber & rhs)
	{
      return  RomansNumber (m_arabian + rhs.m_arabian);
	}
   RomansNumber& RomansNumber::operator += (const RomansNumber & rhs)
	{
     m_arabian += rhs.m_arabian;
		return *this ;
	}
    RomansNumber RomansNumber::operator * (const RomansNumber & rhs)
	{
     
	  return  RomansNumber (m_arabian * rhs.m_arabian);
	}
	RomansNumber&  RomansNumber::operator *= (const RomansNumber & rhs)
	{
     m_arabian *= rhs.m_arabian;
		return *this ;
	}
	RomansNumber RomansNumber:: operator - (const RomansNumber & rhs)
	{
		return  RomansNumber (m_arabian - rhs.m_arabian);
	}
	 RomansNumber& RomansNumber::operator -= (const RomansNumber & rhs)
		 {
     m_arabian -= rhs.m_arabian;
		return *this ;
	     }
	RomansNumber  RomansNumber::operator / (const RomansNumber & rhs)
		{
			return  RomansNumber (m_arabian / rhs.m_arabian);
	    }
	RomansNumber& RomansNumber::operator /= (const RomansNumber & rhs)
		 {
     m_arabian /= rhs.m_arabian;
		return *this ;
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
   {char*  paramArray = new char [50];
	   int length = 1;
	   
	 RomansNumber::ConvertToRomans(rhs.m_arabian, length,paramArray);
	   
	 for (int i = 0;i <length ;i++)
      stream <<  paramArray[i];
      delete[] paramArray;
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
       
		RomansNumber r("XI");
	    
		RomansNumber r1("XV");
		cout<<r.ConvertToArabian("XXIX")<<endl; 
		  int  length = 1;
		
    cout<<endl; 
	RomansNumber r2 =r1+r;
	   r1 =r++;
	   r1 *= r;
	   cout<<r1<<endl;
	   cout<<r<<endl;
	   //assert(r <= r1);
	 cout<<"11111111111111111111111111111111111111111111111"<<endl;
	   return 0;
	
		
		}


