#include "calldispatcher.h"

#include <iostream>
#include <algorithm>
/*bool Box::operator()(const Box& x, const Box& y) const
{ return x < y; }*/

CallDispatcher::CallDispatcher( )
//m_mult(comp)
{




}





void CallDispatcher::connect(Object *sender, const std::string& singal,
                             Object *receiver, const std::string& slot)
{
    bool flag1 = true;


    unordered_map<Object *, unordered_set<string>> un_map1;
    unordered_map<string ,unordered_map<Object *, unordered_set<string>>> un_map2;
  unordered_map<string ,unordered_map<Object *, unordered_set<string>>>::iterator it1;
   unordered_map<Object *, unordered_set<string>> ::iterator it2;
  unordered_map <Object * , unordered_map<string ,unordered_map<Object *,
          unordered_set<string>>>> ::iterator it;
    unordered_set<string> set_str;




            it = m_mult.find(sender);
     if(it != m_mult.end())
    {

           it1 =  it->second.find(singal);
    if(it1 !=it->second.end())


    {

        it2 =  it1 -> second.find(receiver);
   if(it2!= it1->second.end())
            it2->second.insert(slot);
        else
         {
                 set_str.insert(slot);
             it1 ->second.insert(pair <Object *, unordered_set<string>>(receiver,set_str));
         }
    }

      else
            {
            set_str.insert(slot);

        un_map1.insert(pair <Object *, unordered_set<string>>(receiver,set_str));
      flag1 = true;
            }
     if(!flag1)
         it->second.insert(pair<string,unordered_map<Object *,unordered_set<string>>>(singal,it1->second  ));
     else
        it->second.insert(pair<string,unordered_map<Object *,unordered_set<string>>>(singal, un_map1 ));
     m_mult.insert(pair < Object *, unordered_map<string ,unordered_map<Object *,unordered_set<string>>>>
                   (sender,it->second ));

    }
     else
     {
         set_str.insert(slot);
       un_map1.insert(pair<Object *,unordered_set<string>>(receiver, set_str ));
         un_map2.insert(pair<string,unordered_map<Object *,unordered_set<string>>>(singal, un_map1));
         m_mult.insert(pair < Object *, unordered_map<string ,unordered_map<Object *,unordered_set<string>>
                       >>(sender, un_map2));

     }
   }

void CallDispatcher::disconnect(Object *sender, const std::string& singal,
                                Object *receiver, const std::string& slot)
{
    auto   it = m_mult.find(sender);
 auto   it1 =  it ->second.find(singal);
auto   it2 = it1 ->second.find(receiver);

it2->second.erase(slot) ;




/*if(it2->second.empty()) it1 ->erase(it2);
if(it1->empty()) it->erase(it1);
if(it->empty()) m_mult.erase(it);*/

}

void CallDispatcher::sendSignal(Object *sender, const std::string& singal)
{
    Object * q;
   auto   it = m_mult.find(sender);
   if(it ==  m_mult.end() )

   {
       std::cout<<"<nothing>"<< std::endl;
       return;
   }

   auto   it1 =  it ->second.find(singal);

   if(it1 ==  it ->second.end() )
    {
       std::cout<<"<nothing>"<< std::endl;
       return;
   }
       for(auto it2 = it1->second.begin();it2 != it1->second.end(); ++it2)
   { for(auto it3 = it2->second.begin();it3 != it2->second.end(); ++it3)
      {
               q =it2->first;
               cout<<*it3<<endl;



               // q->dispatchMethod(*it3);C:\Users\user\Desktop\pr31help\
               //calldispatcher.cpp:128: ошибка: invalid use of incomplete type 'class Object'
               //q->dispatchMethod(*it3);


               // sender->dispatchMethod(*it3);

     }
}}
