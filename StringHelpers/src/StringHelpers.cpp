#include <StringHelpers.hpp>



bool cStrEqualsTocStr (const char* cStr1, const char* cStr2)
{
    int result = strcmp (cStr1, cStr2);
    return (result == 0);
}


String cStrToStr (char* c_string)
{
    return String (c_string);
}


String constCStrToStr (const char* c_string)
{
    return String (c_string);
}


String boolToStr (bool value)
{
    return std::to_string (value);
}


String intToStr (int value)
{
    return std::to_string (value);
}


String floatToStr (float value)
{
    return std::to_string (value);
}
