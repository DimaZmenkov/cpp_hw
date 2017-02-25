#include <iostream>
#include <condition_variable>
#include <array>
#include <cassert>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
using namespace std;

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

    size_t size() const
    {
        return N;
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
        condition_variable g_queuecheck;
        cout<<"in push_back"<<endl;
        if (full())

        {

            cout<<"full"<<endl;

            std::unique_lock<std::mutex> locker(g_lock_write);     //}

            //flag_write = false;
            while(full())
                g_queuecheck.wait(locker);
            \
        }
        g_lock_write.lock();
        tSize start = m_start%N;
        m_data[start] = elem;
        ++m_start;
        //flag_read = true;

        g_queuecheck.notify_one();
        g_lock_write.unlock();
    }

    T& front()
    {
        condition_variable g_queuecheck;
        cout<<"in front"<<endl;
        if (empty())
            //{
            // throw out_of_range("Buffer is emtpy");
            // }
        {
            \
            std::unique_lock<std::mutex> locker(g_lock_read);     //}
            cout<<"empty"<<endl;

            while(empty())
                g_queuecheck.wait(locker);
        }
        return m_data[m_end%N];
    }

    const T& front() const
    {
        condition_variable g_queuecheck;
        if (empty())
            //{
            //throw out_of_range("Buffer is emtpy");
            //}
        {
            cout<<"empty"<<endl;



            {
                std::unique_lock<std::mutex> locker(g_lock_read);
                //}
                while(empty())
                    g_queuecheck.wait(locker);
            }
        }

        return m_data[m_end%5];
    }

    void pop_front()
    {
        condition_variable g_queuecheck;
        cout<<"in pop_front"<<endl;
        if (empty())
        {

            cout<<"in pop_front empty"<<endl;// throw out_of_range("Buffer is emtpy");
        }
        else
        {

            g_lock_read.lock();
            ++m_end;


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



    //for(int i =0 ;i < 100; i++)
    // {
    std::thread thr1(run);

    std::thread thr2(run);

    thr1.join();

    thr2.join();


    //}

    //cout<<"11111111111111"<<endl;
    return 0;
}

