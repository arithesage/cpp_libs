#ifndef __STRING_HELPERS__
#define __STRING_HELPERS__

#include <cstring>
#include <initializer_list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

using String = std::string;

template <typename Type>
using List = std::vector<Type>;


class StringHelpers
{
    public:
        // Compare 2 C strings
        static bool CStrEqualsTocStr (const char* cStr1, const char* cStr2);

        // Shortcut for crating a string from a C string (char*)
        static String CStrToStr (char* c_string);

        // Concatenate a bunch of C-Strings into a String
        static String Concat (std::initializer_list<const char*> chunks);

        // Concatenate a bunch of C-Strings into a String using
        // the given separator
        static String Concat (std::initializer_list<const char*> chunks,
                              const char* separator);

        // Concatenate a bunch of Strings
        static String Concat (std::initializer_list<String> chunks);

        // Concatenate a bunch of Strings using the given separator
        static String Concat (std::initializer_list<String> chunks, 
                              const char* separator);

        // Concatenate a bunch of Strings using the given separator
        static String Concat (std::initializer_list<String> chunks,
                              String separator);

        // Concatenate a List of Strings using the given separator
        static String Concat (List<String> chunks, String separator);

        // Shortcut for crating a string from a const C string (const char*)
        static String ConstCStrToStr (const char* c_string);

        // Shortcut for obtaining the string representation of an boolean value
        static String BoolToStr (bool value);

        // Shortcut for obtaining the string representation of an integer value
        static String IntToStr (int value);

        // Shortcut for obtaining the string representation of a float value
        static String FloatToStr (float value);
};

#endif
