#include "stdafx.h"
#include <iostream>
using namespace std;

template<typename T>
//# 1
//////////////////////////////////////
//namespase n0
//{
class ImmutableBuffer
{public:
 
ImmutableBuffer(T*, size_t length):
 m_Array(T),
 m_length(length)
 {

 }
~ImmutableBuffer()
{delete[] m_array
}

friend ostream& operator<<(ostream& stream, const ImmutableBuffer & rhs, int pos)
   {
      return stream << rhs.m_array[pos];
   }
bool operator ==(const & rhs)
   {if rhs.m_length != m_length) return false; 
	   for (int i = 0;i < m_length i++)
     if(  rhs.m_array[i] != m_array[i]) return false;
	   return true;
   }
const T& operator [](int pos)
{
	return  m_array[pos];
}
bool operator !=(const & rhs)
{
	return !(rhs == *this);
}

private:
const T* m_array 
size_t m_length;
ImmutableBuffer& operator =(const big_int& rhs)
   {
      if (this != & rhs)
      { 
		  for (int i = 0;i < m_length i++)
        m_array[i] = rhs.m_array[i];
      }
      return *this;
   }

};
int _tmain(int argc, _TCHAR* argv[])
{//#1
	 
		using namespace n0
	double arr[] = {1.0, 2.0, 3.0};
    ImmutableBuffer<double> buff(arr, ARR_SIZE(arr));
    ImmutableBuffer<double> buff2 = buff;
    arr[0] = 0;
    assert(buff[0] == 1.0);

    // equal
    assert(buff == buff2);

    // should fail
    // buff[0] = 42.0;
    // buff    = buff2;

    cout << buff << endl;
	return 0;
}