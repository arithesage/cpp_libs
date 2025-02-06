#include <iostream>

#include <FilesystemHelpers.hpp>


int main ()
{
    bool exists = FSHelpers::IsFile ("/var/tmp");

    std::cout << std::boolalpha << exists << std::endl;

    return 0;
}
