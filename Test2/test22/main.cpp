#include <QCoreApplication>
#include <iostream>
#include<cassert>
#include <string>
//#include <fstream>

#include <map>
//#include <unordered_map>
//#include <utility>
//#include <set>
#include <algorithm>
#include <list>
using namespace std;
template<typename K, typename V>
class Box
{
public:
  K value1;
  V value2;
/*Box& operator = (const Box& rhs)
{if(this!= &rhs)
{
value1 =rhs.value1;
value2 =rhs.value2;
}
return *this;
}*/


};

template<typename K, typename V>
class LRUCache
{
public:
    LRUCache(size_t max_size):
     m_size(max_size),
    m_count(0)
    {

    }


//Box b;
    // put value by key
    void Put(const K& key, const V& value)
    {

    Box< K,  V> b;

    if (m_count < m_size )
    {
       m_elements .insert( pair<K, V>(key, value ));
               b.value1= key; b.value2 = value;
               m_help.push_back(b);
    m_count++;
    }
    else
    {
   b = m_help.front();
           m_help.pop_front();

   m_elements.erase(m_elements.find( b.value1));
    m_elements .insert( pair<K, V>(key, value ));


    b.value1= key; b.value2 = value;
    m_help.push_back(b);

    }

    }


    // Retrieves an entry from the cache that has been cached before
    // using put(). Returns the cached entry. Throws exception,
    // if there is no entry with the key K
    const V& Get(const K& key)
{

if(Exists( key))
    {

    Box< K,  V> b;
      for( auto it = m_help.begin(); it != m_help.end(); ++it)

          if(it -> value1 == key)
          {
              b.value1 = it -> value1;  b.value2 = it -> value2;
              m_help.erase(it);  m_help.push_back(b);  break;
          }

      }


return m_elements.at(key);

  }
    // Checks presence of the value by the given key
    bool Exists(const K& key)
    {
     return m_elements.find(key) != m_elements.end() ;
    }
    // Clears all the entries in the cache
    void Clear()
    {

    m_help.clear();
        m_elements.clear();
    m_count = 0;
    }

    // Returns actual size of the cache: number of currently available elems.

    size_t Size() const
{
return m_count;
}
private:
    list<Box<K,V>> m_help;
    map<K,V> m_elements;
size_t m_size;
size_t m_count;

};

int main()
{

    LRUCache<int, string> cache(3);
    cache.Put(1, "1");
    cache.Put(2, "2");
    cache.Put(3, "3");
//cache.Put(5, "5");
   assert( cache.Get(2) == "2");
    assert( cache.Get(3) == "3");
    cache.Put(4, "4");
//assert(cache.Get(1) == "1");
cout<<"111111";
    return 0 ;
}
