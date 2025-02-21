#ifndef __EVENT_LISTENER__
#define __EVENT_LISTENER__


class Listener
{
    public:
        virtual void Notify () {}
};


template <typename P1>
class Listener1P
{
    public:
        virtual void Notify (P1 p1) {}
};


template <typename P1, typename P2>
class Listener2P
{
    public:
        virtual void Notify (P1 p1, P2 p2) {}
};


template <typename P1, typename P2, typename P3>
class Listener3P
{
    public:
        virtual void Notify (P1 p1, P2 p2, P3 p3) {}
};


template <typename P1, typename P2, typename P3, typename P4>
class Listener4P
{
    public:
        virtual void Notify (P1 p1, P2 p2, P3 p3, P4 p4) {}
};


#endif