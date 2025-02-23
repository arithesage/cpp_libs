#include <Log.hpp>
#include <StringHelpers.hpp>


int main ()
{
    const char* name = "Ari";

    Log::i ("Hello, ${0}.", {name});

    return 0;
}
