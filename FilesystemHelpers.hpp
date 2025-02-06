#ifndef __FILESYSTEM_HELPERS__
#define __FILESYSTEM_HELPERS__

#ifndef __TYPES__
#include <iostream>

using String = std::string;
#endif

#include <ifstream>


class FilesystemHelpers
{
    public:
        static bool IsFile (String path);
        static String MakePath (std::initializer_list<String> pathParts);
};


#endif












