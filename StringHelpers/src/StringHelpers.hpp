#ifndef __STRING_HELPERS__
#define __STRING_HELPERS__

#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>

using String = std::string;



// Compare 2 C strings
bool cStrEqualsTocStr (const char* cStr1, const char* cStr2);


// Shortcut for crating a string from a C string (char*)
String cStrToStr (char* c_string);


// Shortcut for crating a string from a const C string (const char*)
String constCStrToStr (const char* c_string);


// Shortcut for obtaining the string representation of an boolean value
String boolToStr (bool value);


// Shortcut for obtaining the string representation of an integer value
String intToStr (int value);


// Shortcut for obtaining the string representation of a float value
String floatToStr (float value);

#endif
