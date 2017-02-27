//#include "eventmanager.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
//#include "shared_ptr.h"
using namespace std;
class Event
{
public:
    Event ();

    Event (const std::string& description);

    const std::string& getDescription() const;

private:
    std::string m_description;
};

Event::Event ()
    : Event("N/A")
{
}

Event::Event (const std::string& description)
    : m_description(description)
{
}

const std::string& Event::getDescription() const
{
    return m_description;
}


class EventListener
{
public:
    virtual void notify(const Event& ev) = 0;

    virtual ~EventListener() {}
};



class EventManager
{
public:
    static EventManager& getInstance();

    void publishEvent(const Event& ev);

    void addListener(std::shared_ptr<EventListener>& listener/*, const vector<EVENT_TYPE>& ev_type_list*/);

    void removeListener(std::shared_ptr<EventListener>& listener/*, const vector<EVENT_TYPE>& ev_type_list*/);
    EventManager() = default;
private:
    //EventManager() = default;
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    std::vector<std::weak_ptr<EventListener>> m_listeners;
};


EventManager& EventManager::getInstance()
{
    static EventManager inst;
    return inst;
}

void EventManager::publishEvent(const Event& ev)
{
    for( auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
        //if((*it).lock().get()!=0)  (*it).lock() -> notify(ev);
        if ((*it).lock())
        {
            (*it).lock() -> notify(ev);
        }
    cout<<ev.getDescription()<< endl;
}

void EventManager::addListener(shared_ptr<EventListener>& listener)
{
    bool flag = false;

    for( auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
        if(it->lock() == listener )  flag = true;

    //return rListeners.end() ;

    if (!flag )
    {
        weak_ptr<EventListener>  v_ptr =  listener;


        m_listeners.push_back(v_ptr);
        cout << "addListener"<< endl;
    }

}

void EventManager::removeListener(shared_ptr<EventListener>& listener)
{

    weak_ptr<EventListener> v_ptr =  listener;

    for( auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
    {
        if(it->lock() == listener ) m_listeners.erase(it); break;
    }


    //listener = nullptr;
    //v_ptr.reset();


}
struct FileLogger : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

struct ConnectionMgr : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


struct EventHandler : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;

    }
};


int main()
{
    shared_ptr<EventListener> evListener1 = make_shared<FileLogger>();
    shared_ptr<EventListener> evListener2 = make_shared<ConnectionMgr>();
    shared_ptr<EventListener> evListener3 = make_shared<EventHandler>();
    EventManager eventManager1;
    EventManager::getInstance().addListener(evListener1);
    Event event1("Test event!");
    EventManager::getInstance().publishEvent(event1);
    EventManager::getInstance().addListener(evListener1);
    //eventManager1.addListener(evListener1);
    //eventManager1.addListener(evListener1);

    //Event event1;
    evListener1 -> notify(event1);
    //eventManager1.removeListener(evListener1);
    EventManager::getInstance().removeListener(evListener1);


    if(evListener1.use_count())
        evListener1 -> notify(event1);

    //...

    return 0;
}









