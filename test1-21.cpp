#include "stdafx.h"
#include <iostream>
#include <cassert>



using namespace std;

template<typename T>

class Vector
{
public:
 
Vector ( size_t size):
 m_size(size),
 m_count(0)
 {
	 m_array = new T[size];
 }

~Vector()
{
	delete[] m_array;
}


Vector& operator = (const Vector & rhs)
   {
	   
      if (this != & rhs)
      {  
		  //if (m_size== rhs.m_size)
		  for (int i = 0;i < rhs.m_count ;i++)
        m_array[i] = rhs.m_array[i];
      
	  }
      return *this;
   }
Vector (const Vector & rhs)
{
*this = rhs;
}

void push_back(const T& elem)
{
	m_array[m_count++] = elem;
}
size_t size() const
{
return m_count;
}
size_t capacity() const
	{
return m_size;
}
T& operator [](size_t pos) 
{
	return  m_array[pos];
}
const T& operator [](size_t pos) const
{
	return  m_array[pos];
}
void insert( size_t pos, const T& value )
{
	
		 for (int i = 0 ;i <  m_count - pos ;i++)
                m_array[m_count - i] =  m_array[m_count - i - 1];
		  m_array[pos] = value; m_count++;
}
	void erase( size_t pos )
		{
	
		 for (int i = pos ;i <  m_count - 1 ;i++)
                m_array[i] =  m_array[i + 1];
		  m_count--;
	    }
	T& front()
	{
	return m_array[0];
	}
	T& back()
    {
	return m_array[ m_count - 1];
	}
	friend ostream& operator<<(ostream& stream, const Vector & rhs)
   {
	   for (int i = 0;i <rhs. m_count ;i++)
      stream << rhs.m_array[i]<<" ";
      return stream ;
   }
 

bool operator ==(const Vector & rhs)
   {
	   if (rhs. m_count !=  m_count) return false; 
	   for (int i = 0;i <  m_count ;i++)
     if(  rhs.m_array[i] != m_array[i]) return false;
	   return true;
   }

bool operator != ( Vector & rhs) 
{
	return !(rhs == *this);
}
bool operator < (const Vector & rhs) 
{
	if (rhs. m_count !=  m_count) return false; 
	 for (int i = 0;i <  m_count ;i++)
     if(  m_array[i] >= rhs.m_array[i]) return false;
	   return true;
}
bool operator <= (const Vector & rhs) 
{
	return((*this == rhs)||(*this < rhs));
}
bool operator > (const Vector & rhs) 
{
 return !(*this <= rhs);
}
bool operator >= (const Vector & rhs) 
{
 return !(*this < rhs);
}
private:
 T* m_array; 
size_t  m_size;
size_t m_count;

};

int _tmain(int argc, _TCHAR* argv[])
{
	Vector<int> vect(7);
	 for (int i = 0 ;i <  5 ;i++)
	vect.push_back(i);
	 assert(vect[2] == 2);
	 Vector<int> vect1(5);
	  for (int i = 0 ;i <  5 ;i++)
	vect1.push_back(i + 1);
	assert(vect.capacity() == 7);
	assert(vect.size() == 5);
	  assert(vect < vect1);
	assert(vect <= vect1);
	assert(!(vect == vect1));
	assert(!(vect >= vect1));
	assert(!(vect > vect1));
	
	assert((vect != vect1));
	vect = vect1;
	assert(vect == vect1);
	vect.insert(0, 3);
	assert(vect.front() == 3);
	assert(vect.back() == 5);
	assert(vect[5] == 5);
	Vector<int> vect2(7);
	 for (int i = 0 ;i <  5 ;i++)
	vect2.push_back(i);
	vect2.erase(2);
	assert(vect2[2] == 3);
	assert(vect2[3] == 4);
	return 0;
}
