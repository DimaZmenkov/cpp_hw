#include <iostream>
#include <condition_variable>
#include <array>
#include <cassert>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
using namespace std;
//mutex g_lock_read;
//mutex g_lock_write;
//mutex g_lock;
condition_variable g_queuecheck;
bool flag_read;
bool flag_write;
template<typename T, size_t N>
class RingBuffer
{
    array<T, N> m_data;

    typedef unsigned long long tSize;

    unsigned long long m_start = 0;
    unsigned long long m_end = 0;

public:
mutex g_lock_read;
mutex g_lock_write;
//mutex g_lock;
    size_t size() const
    {
        return 5;
    }

    size_t count() const
    {
        return m_start - m_end;
    }

    bool empty() const
    {
        tSize start = m_start % N;
        tSize end   = m_end % N;

        bool result = false;

        if (start == end)
        {
            if (m_start == m_end)
            {
               result = true;
            }
        }

        return result;
    }

    bool full() const
    {
      tSize  start = m_start % N;
      tSize  end   = m_end % N;

        bool result = false;

        if (start == end)
        {
            if (m_start > m_end)
            {
               result = true;
            }
        }

        return result;
    }

    void push_back(const int& elem)
    {
        cout<<"in push_back"<<endl;
        if (full())
        //{
           // throw out_of_range("Buffer is full");
        //}
{

cout<<"full"<<endl;

       std::unique_lock<std::mutex> locker(g_lock_write);     //}

flag_write = false;
while(!flag_write)
        g_queuecheck.wait(locker);
\
    }
g_lock_write.lock();
        tSize start = m_start%N;
        m_data[start] = elem;
        ++m_start;
    flag_read = true;

   g_queuecheck.notify_one();
    g_lock_write.unlock();
    }

    T& front()
    {
        cout<<"in front"<<endl;
        if (empty())
        //{
           // throw out_of_range("Buffer is emtpy");
       // }
 {
      \
       std::unique_lock<std::mutex> locker(g_lock_read);     //}
cout<<"empty"<<endl;
flag_read = false;
while(!flag_read)
        g_queuecheck.wait(locker);
        }
        return m_data[m_end%N];
    }

    const T& front() const
    {
        if (empty())
        //{
            //throw out_of_range("Buffer is emtpy");
        //}
 {
cout<<"empty"<<endl;


flag_read = false;
       {
           std::unique_lock<std::mutex> locker(g_lock_read);
  //}
while(!flag_read)
        g_queuecheck.wait(locker);
        }
    }

        return m_data[m_end%5];
    }

    void pop_front()
    {
        cout<<"in pop_front"<<endl;
        if (empty())
        {
            flag_read = false;
           cout<<"in pop_front empty"<<endl;// throw out_of_range("Buffer is emtpy");
        }
   else{

g_lock_read.lock();
        ++m_end;
        flag_write = true;

g_queuecheck.notify_one();

g_lock_read.unlock();
}
}
};
void run()
{
    cout<<"in run"<<endl;
 RingBuffer<int, 2>  rb;

rb.push_back(1);
rb.front();

rb.pop_front();
}

int main()
{
    flag_write = true;  flag_read = true;



     std::thread thr1(run);

    std::thread thr2(run);

    thr1.join();

    thr2.join();




cout<<"11111111111111"<<endl;
return 0;
}
