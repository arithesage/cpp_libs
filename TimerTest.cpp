#include <iostream>
#include <Timer.hpp>

using std::cerr;
using std::cout;
using std::endl;


Timer timer;


class Test : public TimerListener
{
    private:
        bool running = false;

        void onTimeout () override
        {
            cout << "Timer finished.\n";
            running = false;
        }

    public:
        Test ()
        {
            timer.OnTimeout (this);
        }

        void Run ()
        {
            running = true;
            timer.Start ();

            while (running)
            {
                timer.Update ();
            }
        }
};


int main ()
{
    Test test;
    test.Run ();   

    return 0;
}
