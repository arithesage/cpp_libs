#include <StringHelpers.hpp>
#include <VectorHelpers.hpp>


bool StringHelpers::CStrEqualsTocStr (const char* cStr1, const char* cStr2)
{
    int result = strcmp (cStr1, cStr2);
    return (result == 0);
}


String StringHelpers::CStrToStr (char* c_string)
{
    return String (c_string);
}


String StringHelpers::Concat (std::initializer_list<const char*> chunks)
{
    return Concat (chunks, "");
}


String StringHelpers::Concat (std::initializer_list<const char*> chunks,
                              const char* separator)
{
    List<String> chunkList;

    std::initializer_list<const char*>::iterator it;

    for (it = chunks.begin(); it != chunks.end(); it ++)
    {
        chunkList.push_back (String (*it));
    }

    return Concat (chunkList, separator);
}


String StringHelpers::Concat (std::initializer_list<String> chunks)
{
    return Concat (chunks, "");
}


String StringHelpers::Concat (std::initializer_list<String> chunks,
                              const char* separator)
{
    return Concat (chunks, String (separator));
}


String StringHelpers::Concat (std::initializer_list<String> chunks, 
                              String separator)
{
    List<String> allChunks = VectorHelpers::Pack<String> (chunks);

    String str = "";

    for (String chunk : chunks)
    {
        str += chunk;
        str += separator;
    }

    return str;
}


String StringHelpers::Concat (List<String> chunks, String separator)
{
    String str = "";

    for (String chunk : chunks)
    {
        str += chunk;
        str += separator;
    }

    return str;
}


String StringHelpers::ConstCStrToStr (const char* c_string)
{
    return String (c_string);
}


String StringHelpers::BoolToStr (bool value)
{
    return std::to_string (value);
}


String StringHelpers::IntToStr (int value)
{
    return std::to_string (value);
}


String StringHelpers::FloatToStr (float value)
{
    return std::to_string (value);
}
