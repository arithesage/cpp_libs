#ifndef __LOG__
#define __LOG__

#include <iostream>


using String = std::string;


class Log
{
    public:
        // Write DEBUG messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void d (String message);

        // Write ERROR messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void e (String message);

        // Write INFO messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void i (String message);

        // Write WARNING messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void w (String message);
};


#endif
