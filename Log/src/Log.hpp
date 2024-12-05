#ifndef __LOG__
#define __LOG__

#include <iostream>

using String = std::string;




class Log
{
    public:
        // Write DEBUG messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void d (String message)
        {
            std::cout << "[DEBUG] " << message << std::endl;
        }


        // Write ERROR messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void e (String message)
        {
            std::cerr << "[ERROR] " << message << std::endl;
        }


        // Write INFO messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void i (String message)
        {    
            std::cout << "[INFO] " << message << std::endl;
        }


        // Write WARNING messages.
        // For appending int, float and boolean values, use the iS, fS and bS functions.
        static void w (String message)
        {
            std::cerr << "[WARNING] " << message << std::endl;
        }
};


#endif
