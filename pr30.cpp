#include <iostream>
#include <condition_variable>
#include <array>
#include <cassert>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
//#include <QMutex>
using namespace std;

template<typename T, size_t N>
class RingBuffer
{
    array<T, N> m_data;

    typedef unsigned long long tSize;

    unsigned long long m_start = 0;
    unsigned long long m_end = 0;


public:

    mutable mutex g_lock_read;
    mutable mutex g_lock_write;

    size_t size() const
    {
        return N;
    }

    size_t count() const
    {
        return m_start - m_end;
    }




    void push_back(const int& elem)
    {
        condition_variable g_queuecheck;
        bool flag;
        cout<<"in push_back"<<endl;
        g_lock_read.lock();
        if (full())

        {

            cout<<"full"<<endl;

            std::unique_lock<std::mutex> locker(g_lock_write);     //}

            //flag_write = false;
            while(flag)
            {
                g_queuecheck.wait(locker);
                flag = full();
            }
        }


        tSize start = m_start%N;
        m_data[start] = elem;
        ++m_start;
        //flag_read = true;

        //g_queuecheck.notify_one();
        g_queuecheck.notify_all();
        g_lock_read.unlock();

    }

    T& front()
    {
        bool flag;
        condition_variable g_queuecheck;
        cout<<"in front"<<endl;
        g_lock_write.lock();
        if (empty())
            //{
            // throw out_of_range("Buffer is emtpy");
            // }
        {
            \
            std::unique_lock<std::mutex> locker(g_lock_read);     //}
            cout<<"empty"<<endl;

            while(flag)
            {
                g_queuecheck.wait(locker);
                flag = empty();
            }
        }
        g_lock_write.unlock();
        return m_data[m_end%N];
    }

    const T& front() const
    {

        condition_variable g_queuecheck;
        g_lock_write.lock();
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
                {

                    g_queuecheck.wait(locker);

                }
            }
        }
        g_lock_write.unlock();
        return m_data[m_end%N];
    }


    void pop_front()
    {
        condition_variable g_queuecheck;
        //g_lock_write.lock();
        cout<<"in pop_front"<<endl;

        if (empty())
        {

            cout<<"in pop_front empty"<<endl;// throw out_of_range("Buffer is emtpy");
        }
        else
        {


            std::lock_guard<std::mutex> locker( g_lock_read);
            ++m_end;


            //g_queuecheck.notify_one();
            g_queuecheck.notify_all();
            //g_lock_write.unlock();
        }
    }

    bool full() const
    {

        g_lock_write.lock();
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
        g_lock_write.unlock();
        return result;
    }
    bool empty() const
    {
        g_lock_read.lock();
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

        g_lock_read.unlock();
        return result;
    }



};


//template<typename T, size_t N>
void run(RingBuffer<int, 2>& rb )
{
    cout<<"in run"<<endl;


    rb.push_back(1);
    rb.front();

    rb.pop_front();
}

int main()
{

    RingBuffer<int, 2>  rb;

    //for(int i =0 ;i < 100; i++)
    //{
    std::thread thr1(run,std::ref(rb)  );

    std::thread thr2(run, std::ref(rb));
    std::thread thr3(run, std::ref(rb));
    std::thread thr4(run, std::ref(rb));
    std::thread thr5(run, std::ref(rb));
    thr1.join();

    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();
    //cout<<"i="<<i<<endl;
    //}

    //cout<<"11111111111111"<<endl;
    return 0;
}

