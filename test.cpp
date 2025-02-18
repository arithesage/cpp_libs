//#include <Common.hpp>
#include <iostream>

#include <Timer.hpp>

using std::cout;
using std::endl;

bool t = false;
bool end = false;


void onTick ()
{
    if (!t)
    {
        cout << "Tick\n";
        t = true;
    }
    else
    {
        cout << "Tock\n";
        t = false;
    }
}


void onStop ()
{
    end = true;
}


int main ()
{
    Timer tick (1.0f, onTick, 20);
    tick.OnStop (onStop);
    tick.Start ();

    while (!end)
    {
        tick.Update ();
    }

    cout << "Finished.\n";

    return 0;
}
