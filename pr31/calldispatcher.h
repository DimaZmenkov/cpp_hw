#ifndef CALLDISPATCHER_H
#define CALLDISPATCHER_H
#include <string>
#include <memory>
#include <unordered_map>//unordered_
#include<unordered_set>
using namespace std;


class Object;


//bool comp(const Box& b1, const Box& b2 );
class CallDispatcher
{
private:
 std::shared_ptr<CallDispatcher> m_dispatcher;
    //...
  unordered_map < Object *, unordered_map<string ,unordered_map<Object *,unordered_set<string>>>> m_mult;


public:
    typedef std::shared_ptr<CallDispatcher> Ptr;

    CallDispatcher();

    void connect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);


void disconnect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);

    void sendSignal(Object* sender, const std::string& singal);
};
#endif // CALLDISPATCHER_H
//bool comp()
