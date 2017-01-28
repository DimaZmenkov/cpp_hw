#include "stdafx.h"
#include <iostream>

using namespace std;


template<typename T, int N=16>
class stack
{
public:
    stack()
        : m_data()
        , m_last(0)
    {

    }

    void push(const T& value)
    {
        m_data[m_last++] = value;
    }

    T pop()
    {
        return m_data[m_last--];
    }

private:
    T m_data[N];
    int m_last;
};


template< int N>

class stack<bool, N>
{
public:
    stack()
        : m_data()
        , m_last(0)
    {
    }

    void push(const bool & value)
    {
        //std::cout << __PRETTY_FUNCTION__ << std::endl;

        int num_elem = (m_last) / 8;
        int offset_elem = (m_last) % 8;

        m_data[num_elem] ^= (-value ^ m_data[num_elem])
                            & (1 << (7-offset_elem));

        m_last++;
    }

    bool pop()
    {
		int num_elem = (m_last - 1) / 8;
        int offset_elem = (m_last - 1) % 8;
         m_last--;
			return  m_data[num_elem] & (1 << (7-offset_elem)) ;
    }

private:
    char m_data[N];
    int m_last;
};


int _tmain(int argc, _TCHAR* argv[])
{
	stack<bool,5> stk;
	stk.push(1);
	stk.push(0);
    stk.push(1);
	stk.push(1);
	stk.push(1);
	stk.push(0);
	cout<< stk.pop()<<endl;
	cout<< stk.pop()<<endl;
	cout<< stk.pop()<<endl;
	cout<< stk.pop()<<endl;
	cout<< stk.pop()<<endl;
	cout<< stk.pop()<<endl;
	stk.push(1);
	stk.push(0);
	cout<< stk.pop()<<endl;
	stk.push(1);
	cout<< stk.pop()<<endl;
	cout<< stk.pop()<<endl;
	return 0;
}

