#include <iostream>

#include <Log.hpp>
#include <StringHelpers.hpp>


int main ()
{
    String path = StringHelpers::Concat ({"home", "javier", "tmp"}, "/");
    std::cout << path << std::endl;

    return 0;
}
