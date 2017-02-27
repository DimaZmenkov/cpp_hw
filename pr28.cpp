//#ifndef FORWARD_LIST_H
//#define FORWARD_LIST_H

#include <iostream>
#include<cassert>
namespace my {


template<typename T>
struct fwd_list_Node
{
    T data;
    fwd_list_Node<T>* next;
};


template<typename T, typename RetT=T>
struct fwd_list_iterator : public std::iterator<std::forward_iterator_tag, T>
{
    fwd_list_iterator()
        : m_current (nullptr)
    {
    }

    fwd_list_iterator(my::fwd_list_Node<T>* ptr)
        : m_current (ptr)
    {
    }

    RetT& operator*()
    {
        return m_current->data;
    }

    fwd_list_iterator& operator++()
    {
        m_current = m_current->next;
        return *this;
    }

    fwd_list_iterator operator++(int)
    {
        fwd_list_iterator tmp(m_current);
        ++(*this);
        return tmp;
    }

    bool operator==(const fwd_list_iterator& rhs)
    {
        return m_current==rhs.m_current;
    }

    bool operator!=(const fwd_list_iterator& rhs)
    {
        return !(*this==rhs);
    }

private:
    fwd_list_Node<T>* m_current;
};


template<class T>
class forward_list
{
    fwd_list_Node<T>* head;

public:

    typedef fwd_list_iterator<T> iterator;
    typedef fwd_list_iterator<T, const T> const_iterator;

    forward_list()
        : head(nullptr)
    {
    }

    forward_list(const forward_list& rhs)
        : head(nullptr)
    {
        for(const T& elem : rhs)
        {
            push_front(elem);
        }

        reverse();
    }

    forward_list(forward_list&& rhs)
        : head(nullptr)
    {
        rhs.swap(*this);
    }

    forward_list& operator=(const forward_list& rhs)
    {
        forward_list(rhs).swap(*this);
        return *this;
    }

    forward_list& operator=(forward_list&& rhs)
    {
        forward_list(std::move(rhs)).swap(*this);
        return *this;
    }

    void swap(forward_list& rhs)
    {
        std::swap(rhs.head, head);
    }

    const T& front()
    {
        return head->data;
    }

    T pop_front()
    {
        T data = head->data;
        fwd_list_Node<T>* tmp = head->next;
        delete head;
        head = tmp;
        return data;
    }

    bool empty()
    {
        return head==nullptr;
    }

    void push_front(const T& value)
    {
        fwd_list_Node<T>* tmp = new fwd_list_Node<T>{value, nullptr};
        if (head)
        {
            tmp->next = head;
        }
        head = tmp;
    }

    void push_front(T&& value)
    {
        fwd_list_Node<T>* tmp = new fwd_list_Node<T>{std::move(value), nullptr};
        if (head)
        {
            tmp->next = head;
        }
        head = tmp;
    }



    void reverse()
    {
        fwd_list_Node<T>*new_head = nullptr;
        //?????? ???????? ??????? ??????
        for(fwd_list_Node<T>*pos=head;pos;)
        {
            //?????? ? ?????? ?????? ??????
            fwd_list_Node<T>*save_next=pos->next;
            pos->next=new_head;
            new_head=pos;
            pos=save_next;
        }
        //?????? ?? ???????
        head=new_head;
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(nullptr); // replace with sentinal object?
    }

    const_iterator begin() const
    {
        return const_iterator(head);
    }

    const_iterator end() const
    {
        return const_iterator(nullptr);
    }

    const_iterator cbegin() const
    {
        return const_iterator(head);
    }

    const_iterator cend() const
    {
        return const_iterator(nullptr);
    }

    ~forward_list()
    {
        while(head)
        {
            fwd_list_Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

};





template<typename T>
struct list_Node
{
    T data;
    list_Node<T>* next;
    list_Node<T>* prev;
};


template<typename T, typename RetT=T>
struct list_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
    list_iterator()
        : m_current (nullptr)
    {
    }

    list_iterator(my::list_Node<T>* ptr)
        : m_current (ptr)
    {
    }

    RetT& operator*()
    {
        return m_current->data;
    }

    list_iterator& operator++()
    {
        m_current = m_current->next;
        return *this;
    }

    list_iterator operator++(int)
    {
        list_iterator tmp(m_current);
        ++(*this);
        return tmp;
    }

    list_iterator& operator--()
    {
        m_current = m_current->prev;
        return *this;
    }

    list_iterator operator--(int)
    {
        list_iterator tmp(m_current);
        --(*this);
        return tmp;
    }

    bool operator==(const list_iterator& rhs)
    {
        return m_current==rhs.m_current;
    }

    bool operator!=(const list_iterator& rhs)
    {
        return !(*this==rhs);
    }

private:
    list_Node<T>* m_current;
};



template<class T>
class list
{

    list_Node<T>* const
    sentinel = new list_Node<T>{T(), nullptr, nullptr};
    list_Node<T>* head = sentinel;
    list_Node<T>* tail = sentinel;

    void swap(list& rhs)
    {
        std::swap(rhs.head, head);
        std::swap(rhs.tail, tail);
        std::swap(rhs.sentinel, sentinel);
    }

    void update_sentinel()
    {
        tail->next = sentinel;
        sentinel->prev = tail;
    }

    void update_tail()
    {
        if (sentinel == tail)
        {
            tail = head;
        }
        if (sentinel == head)
        {
            tail = head;
        }
    }

public:
    typedef list_iterator<T> iterator;
    typedef list_iterator<T, const T> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    list()
    {
    }

    list(const list& rhs)
    {
        for(const T& elem : rhs)
        {
            push_front(elem);
        }

        reverse();
    }

    list(list&& rhs)
    {
        rhs.swap(*this);
    }

    list& operator=(const list& rhs)
    {
        list(rhs).swap(*this);
        return *this;
    }

    list& operator=(list&& rhs)
    {
        list(std::move(rhs)).swap(*this);
        return *this;
    }

    const T& front()
    {
        return head->data;
    }

    const T& back()
    {
        return tail->data;
    }

    T pop_front()
    {
        T data = head->data;
        list_Node<T>* tmp = head->next;
        delete head;
        head = tmp;
        update_tail();
        update_sentinel();
        return data;
    }

    T pop_back()
    {
        T data = tail->data;
        list_Node<T>* tmp = tail->prev;
        delete tail;
        tail = tmp;
        //update_tail();
        update_sentinel();
        return data;
    }

    void reverse()
    {
        list_Node<T>*new_head = nullptr;

        list_Node<T>* tmp = tail;
        //T value = front();

        //?????? ???????? ??????? ??????
        //list_Node<T>*new_tail = nullptr;
        //list_Node<T>*head1 =  head;

        for(list_Node<T>*pos=head;pos;)
        {
            //?????? ? ?????? ?????? ??????
            list_Node<T>*save_next = pos->next;
            pos->next=new_head;
            new_head=pos;
            // pos->next = pos->prev;
            pos->prev =save_next;//->next;

            pos=save_next;
            //pop_front();
            //push_front(value);
        }
        //sentinel = head;
        tail = head;
        //tail->next = nullptr;
        //?????? ?? ???????
        head =new_head;
        //pop_front();
        //push_front(value);
        head ->prev= tmp;
        head =head ->prev;
        head ->prev = nullptr;
        tail-> next = nullptr;
        //update_tail();
        //update_sentinel();

    }
    /*void    reverse()
    {
        if( head == nullptr )
        {
            return;
        }

        for(;;)
        {
            std::swap
                (
                    head->prev,
                    head->next
                );

           list_Node<T>*  prev1    =   head->prev;

            if( prev1 == nullptr )
            {
                break;
            }

            head   =   prev1;
        }//for
    }*/

    bool empty()
    {
        return head==sentinel;
    }

    void push_front(const T& value)
    {
        list_Node<T>* tmp = new list_Node<T>{value, nullptr, sentinel};
        if (head != sentinel)
        {
            tmp->next = head;
            head->prev = tmp;
        }
        head = tmp;
        update_tail();
        update_sentinel();

    }

    void push_back(T value)
    {
        //list_Node<T>* tmp = new list_Node<T>{value, nullptr, sentinel};
        list_Node<T>* tmp = new list_Node<T>{value,nullptr, sentinel };

        //if (tail != sentinel)
        // cout<<"tail->data="<<tail->data<<endl;
        //if (head != sentinel)
        if (head != sentinel)
        {
            tmp->prev = tail;
            tail->next  = tmp;
            //tmp->prev = tail;
            tail  =  tmp;

        }
        else
        {
            head = tmp;
            // head ->next = nullptr;
            // head ->prev = nullptr;
        }
        update_tail();
        update_sentinel();
    }

    /* void push_back( int data)
    {
       // if (Where == NULL && _size != 0) // некорректный указатель
           // return NULL;
      list_Node<T>* tmp = new list_Node<T>{data,sentinel, nullptr};
        //ListNode* pNewNode = new ListNode(data);
       // if (Where == NULL && _size == 0)
        //{
           // head = pNewNode;
            //tail = pNewNode;
       // }
        //else
       // {
            // Есть следующий элемент
           /* if (Where->next)
            {
                ListNode* pNextNode = Where->next;
                Where->next = pNewNode;
                pNewNode->prev = Where;
                pNewNode->next = pNextNode;
                pNextNode->prev = pNewNode;
            }
            // Where = _pEnd
            //else
            if (head!
                tail->next = tmp;
                tmp->prev = tail;
                tail = tmp;
           // }
       // }
        //_size++;
        //return pNewNode;
   // }
    }*/

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(sentinel);
    }

    const_iterator begin() const
    {
        return const_iterator(head);
    }

    const_iterator end() const
    {
        return const_iterator(sentinel);
    }

    const_iterator cbegin() const
    {
        return const_iterator(head);
    }

    const_iterator cend() const
    {
        return const_iterator(sentinel);
    }

    reverse_iterator rbegin() const
    {
        return reverse_iterator(sentinel);
    }

    reverse_iterator rend() const
    {
        return reverse_iterator(head);
    }

    const_reverse_iterator crbegin() const
    {
        return const_reverse_iterator(sentinel);
    }

    const_reverse_iterator crend() const
    {
        return const_reverse_iterator(head);
    }

    ~list()
    {
        while(head != sentinel)
        {
            list_Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }

        delete sentinel;
    }

};
}


int main()
{
    using namespace my;

    my::list<int> dlist;

    // dlist.push_back(1);
    // dlist.push_back(2);
    // dlist.push_back(3);
    dlist.push_front(1); dlist.push_front(1); dlist.push_front(1);
    assert(dlist.empty()==false);

    //assert(dlist.empty()==false);

    for(auto& elem: dlist)
    {
        std::cout << elem <<std:: endl;
    }

    // std::cout << "dlist: " << dlist << std::endl;
    my::list<int> dlist2 = dlist;// runtime error
    // cout << "dlist2: " << dlist2 << endl;

    ////            assert(dlist.back() ==dlist2.back());
    ////            assert(dlist.front()==dlist2.front());

    ////            cout << "--reversed--" << endl;
    ////            for(auto it = dlist.rbegin(); it!=dlist.rend(); ++it)
    ////            {
    ////                cout << *it << endl;
    ////            }

    ////            {
    ////                my::list<string> list;
    ////                list.push_back("xxx");
    ////                list.pop_back();
    ////                list.push_back("first");
    ////                list.push_back("second");

    ////                list.reverse();

    ////                assert(*(list.begin()) == "second");
    ////                assert(*(list.end())   == "first");
    ////                cout << "list: " << list << endl;
    ////            }

    ////            cout << *(dlist.rbegin()) << endl;
    ////            assert(dlist.back() ==*(dlist.rbegin()));

    ////            dlist.pop_back();
    ////            cout << "popped back: " << dlist << endl;
    ////            assert(dlist.empty()==false);

    ////            dlist.pop_front();
    ////            cout << "popped front: " << dlist << endl;
    ////            assert(dlist.empty()==false);

    ////            dlist.pop_front();
    ////            cout << "popped front: " << dlist << endl;
    ////            assert(dlist.empty()==true);

    ////            dlist.push_front(11);
    ////            auto it = dlist.begin();
    ////            *(it) = 42;
    ////            cout << "push & modify: " << dlist << endl;

    ////            assert(*(  dlist.begin())   ==dlist.front());
    ////            assert(*(--dlist.end())     ==dlist.back());
    ////            assert(*(  dlist.rbegin())  ==dlist.back());
    ////            assert(*(--dlist.rend())    ==dlist.front());
    ////            assert(42 == dlist.front());

    ////            dlist.pop_back();
    ////            cout << "popped back: " << dlist << endl;
    ////            assert(dlist.empty()==true);






    /*forward_list<int> f;
 f.push_front(1); f.push_front(2);f.push_front(3);f.reverse();
 int p = f.pop_front();std::cout<<p<<std::endl;
 p = f.pop_front();std::cout<<p<<std::endl;p = f.pop_front();std::cout<<p<<std::endl;
list<int> f1;
std::cout<<"list"<<std::endl;

 std::cout<<"list after push "<<std::endl;



  f1.push_front(3);
  f1.push_front(4);f1.push_front(5);f1.push_front(6); f1.push_front(7);
  f1.reverse();


  p = f1.pop_front();std::cout<<p<<std::endl;
  p = f1.pop_front();std::cout<<p<<std::endl ;
  p = f1.pop_front();std::cout<<p<<std::endl;
  p = f1.pop_front(); std::cout<<p<<std::endl;
  p = f1.pop_front();std::cout<<p<<std::endl;
   f1.push_front(3);
  f1.push_front(4);f1.push_front(5);f1.push_front(6); f1.push_front(7);
   p = f1.pop_front();std::cout<<p<<std::endl;
  p = f1.pop_front();std::cout<<p<<std::endl ;
  p = f1.pop_front();std::cout<<p<<std::endl;
  p = f1.pop_front(); std::cout<<p<<std::endl;
 // p = f1.pop_front();std::cout<<p<<std::endl;
  std::cout<<"111111111111111111111111111111"<<std::endl;
/*f1.push_front(4);f1.push_front(5);f1.push_front(6); f1.push_front(7);
p = f1.pop_back();std::cout<<p<<std::endl;
p = f1.pop_back();std::cout<<p<<std::endl;
p = f1.pop_back();std::cout<<p<<std::endl;
p = f1.pop_back();std::cout<<p<<std::endl;
//p = f1.pop_back();std::cout<<p<<std::endl;
 std::cout<<"222222222222222222222222222222"<<std::endl;

f1.push_back(3);
  f1.push_back(4);f1.push_back(5);f1.push_back(6); f1.push_back(7);

 p = f1.pop_back();std::cout<<p<<std::endl;
  p = f1.pop_back();std::cout<<p<<std::endl ;
  p = f1.pop_back();std::cout<<p<<std::endl;
  p = f1.pop_back(); std::cout<<p<<std::endl;
  p = f1.pop_back();std::cout<<p<<std::endl;



/*p = f1.pop_back();std::cout<<p<<std::endl;
p = f1.pop_back();std::cout<<p<<std::endl;
p = f1.pop_back();std::cout<<p<<std::endl;
p = f1.pop_back();std::cout<<p<<std::endl;
p = f1.pop_back();std::cout<<p<<std::endl;

//f1.push_front(1);

  //p = f1.pop_back();
//std::cout<<p<<std::endl;
 //cout<<"1111111111111";*/
    return 0;
    //}






}
