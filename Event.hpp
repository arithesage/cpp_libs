#ifndef __EVENT__
#define __EVENT__

#include <Types.hpp>
#include <Listener.hpp>

class Event
{
    protected:
        List<Listener> listeners;
        
    public:
        void Fire ();
};


void Event::Fire ()
{
    for (Listener listener : listeners)
    {
        listener.notify ();
    }
}

#endif