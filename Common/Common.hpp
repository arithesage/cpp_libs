#ifndef __COMMON__
#define __COMMON__

#include <LangHelpers.hpp>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;


namespace Common
{


    void Print (const char* message, Args<const char *> params);
}

#endif