#include <QCoreApplication>
#include <iostream>
#include <cassert>
using namespace std;



template<int B, int E, int S = 1>
class  RangeIterator
        : public std::iterator<std::input_iterator_tag, int >
{



public:
  RangeIterator(const RangeIterator &it):
  m_count(it.m_count)
  {
  }

  int  operator*()
        {



          return B + m_count*S ;
        }


 RangeIterator & operator++()
      {
         ++m_count ;
          return *this;
      }
 RangeIterator  operator++(int)
    {
        RangeIterator  tmp(m_count);
        ++(*this);
        return tmp;
    }
 bool operator==(const RangeIterator & rhs)
     {
         return m_count == rhs.m_count;
     }
 bool operator!=(const RangeIterator & rhs)
    {
        return !(*this==rhs);
    }


RangeIterator(size_t count ):
    m_count(count)
 {

  }
private:
size_t m_count;
    };

template<int B, int E, int S = 1>
class  RangeReverseIterator
        : public std::iterator<std::input_iterator_tag, int >
{



public:
  RangeReverseIterator(const RangeReverseIterator &it):
  m_count(it.m_count)
  {
  }

  int  operator*()
        {
      size_t count1 = (E - B)/S ;
           if(!count1)
      return B  ;
        else
           if  ((E - B)%S == 0)
           return E  - (m_count + 1)*S;
           else
               return E  -E%S - m_count *S;

  }


 RangeReverseIterator & operator++()
      {
         ++m_count ;
          return *this;
      }
 RangeReverseIterator  operator++(int)
    {
        RangeReverseIterator  tmp(m_count);
        ++(*this);
        return tmp;
    }
 bool operator==(const RangeReverseIterator & rhs)
     {
         return m_count ==rhs.m_count;
     }
 bool operator!=(const RangeReverseIterator & rhs)
    {
        return !(*this==rhs);
    }


RangeReverseIterator(size_t count ):
    m_count(count)
 {

  }
private:
size_t m_count;
    };

template<int B, int E, int S = 1>
class Range
  {
   public:
Range()

{


   if ((E - B)%S == 0)
   m_size  = (E - B)/S ;
       else
          m_size  = (E - B)/S + 1  ;
           ;

}

    typedef RangeIterator<B, E,S> iterator;
     typedef RangeReverseIterator<B, E,S> reverse_iterator;

  RangeIterator<B, E,S>   begin()

      {

      return iterator(0 );
      }

  iterator end()
  {

      return iterator( m_size   );
  }

    reverse_iterator rbegin()

      {

      return reverse_iterator(0 );
      }

  reverse_iterator rend()
  {

      return reverse_iterator( m_size   );
  }
 /* friend iterator find(iterator first, iterator last,const int& value )
{
       for(auto it = first; it != last ; ++it )
           if(*it == value) return  it;

}*/
   private:

int * m_array;
size_t m_size;
};


int main()
{

for (auto elem : Range<1, 5>())
{
    std::cout << elem<<" " ; // 1 2 3 4
}
cout <<endl;
for (auto elem : Range<0, 10, 2>())
{
   std::cout << elem <<" "; //0 2 4 6 8
}
cout <<endl;
for (auto elem : Range<20, 50, 1000>())
{
   std:: cout << elem << " "; // 20
}
cout <<endl;
Range<1,30> r;
for (auto it = r.rbegin();it !=r.rend();++it  )
{
    std::cout << *it<<" " ; //
}
cout <<endl;
find(r.begin(), r.end(),1);

assert( count_if(r.begin(), r.end(), [](int e){return e>20;}) == 9);

//std::cout<<
//std::cout<<"11111111111111111"<<std::endl;
return 0;
}

