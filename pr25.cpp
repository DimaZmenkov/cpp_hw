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

	int test;
	stack<bool,5> stk;
	const int quantity = 10;
	for (int i = 0;i < quantity; i++)
	{
		test = rand()%2;
	cout<<"push"<<test<<endl;
	stk.push(test);
	}
	for (int i = 0;i < quantity; i++)
		cout<<"pop"<<stk.pop()<<endl;
	
	return 0;
}

