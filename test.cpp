#include <iostream>
#include <Types.hpp>

using std::cout;
using std::endl;


class Test
{
    
};


class Result
{

};




int main ()
{
    Test t;
    Result r;

    Anything s (t);

    if (s.Is<Test>())
    {
        cout << "S is of type Test.\n";
    }
    else
    {
        cout << "S isn't of type Test.\n";
    }

    return 0;
}
