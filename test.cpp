#include <iostream>
//#include <filesystem>

//namespace fs = std::filesystem;

#include <Types.hpp>


class Resource
{

};


class SDLFont : public Resource
{

};


int main ()
{
    std::cout << std::boolalpha << Type<SDLFont>::InheritsFrom<Resource>() << std::endl;

//    SDLFont* f = new SDLFont ();
//    std::cout << std::boolalpha << Type<SDLFont*>::IsPtr() << std::endl;

//    delete f;
/*
    fs::path tmp ("/var/tmp");
    std::cout << std::boolalpha << fs::exists(tmp) << std::endl;
*/
    return 0;
}
