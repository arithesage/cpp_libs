#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

#include <Listener.hpp>
#include <Event.hpp>


class CatMeowEvent : public Event
{
    
};


class CatListener : public Listener
{
    protected:
        virtual void onCatMeow () = 0;
        
    public:
        void Notify () override
        {
            onCatMeow ();
        }
};


class Cat
{
    public:
        void Meow ()
        {
            cout << "Meooow!\n";
            meowEvent.Fire ();
        }
};


class Dog : public CatListener
{
    protected:
        void onCatMeow () override
        {
            cout << "Warf!\n";
        }
        
    public:
        Dog ()
        {
            meowEvent.Subscribe (this);
        }
};



CatMeowEvent meowEvent;

int main()
{
    Cat cat;
    Dog dog;
    
    cat.Meow ();
    
    return 0;
}

