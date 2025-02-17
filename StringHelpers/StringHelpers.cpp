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


String StringHelpers::Concat (Args<const char*> chunks)
{
    return Concat (chunks, "");
}


String StringHelpers::Concat (Args<const char*> chunks, const char* separator)
{
    List<const char*> _chunks = ListFromArgs<const char*> (chunks);
    
    return Concat (_chunks, separator);
}


String StringHelpers::Concat (List<const char*> chunks, const char* separator)
{
    String str = String ("");

    for (int c = 0; c < chunks.size(); c ++)
    {
        str += String (chunks[c]);

        if (c < (chunks.size() - 1))
        {
            str += separator;
        }
    }

    return str;
}


String StringHelpers::Concat (Args<const char*> chunks, String separator)
{
    List<const char*> _chunks = ListFromArgs<const char*> (chunks);

    return Concat (_chunks, separator.c_str());
}


String StringHelpers::Concat (List<const char*> chunks, String separator)
{
    return Concat (chunks, separator.c_str());
}


String StringHelpers::Concat (Args<String> chunks)
{
    List<String> _chunks = ListFromArgs<String> (chunks);

    return Concat (_chunks, "");
}


String StringHelpers::Concat (Args<String> chunks, const char* separator)
{
    List<String> _chunks = ListFromArgs<String> (chunks);

    return Concat (_chunks, separator);
}


String StringHelpers::Concat (List<String> chunks, const char* separator)
{
    String str = String ("");

    for (int c = 0; c < chunks.size(); c ++)
    {
        str += chunks[c];

        if (c < (chunks.size() - 1))
        {
            str += separator;
        }
    }

    return str;
}


String StringHelpers::Concat (Args<String> chunks, String separator)
{    
    List<String> _chunks = ListFromArgs<String> (chunks);

    return Concat (chunks, separator.c_str());
}


String StringHelpers::Concat (List<String> chunks, String separator)
{
    return Concat (chunks, separator.c_str());
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


bool StringHelpers::Has (const char* text, const char* chunk)
{
    String _text (text);

    return (_text.find (chunk) >= -1);
}


bool StringHelpers::Has (const char* text, String chunk)
{    
    return Has (text, chunk.c_str ());
}


String StringHelpers::Replace (const char* text, 
                               const char* chunk, 
                               const char* newChunk)
{
    String _text (text);
    String _chunk (chunk);

    int chunkPos = _text.find (_chunk);

    if (chunkPos >= 0)
    {
        _text.replace (chunkPos, _chunk.size(), newChunk);
    }

    return _text;
}


String StringHelpers::ReplaceAll (const char* text, 
                                  Args<const char*> chunks, 
                                  Args<const char*> newChunks)
{
    const char* _text (text);

    List<const char*> _chunks = ListFromArgs<const char*> (chunks);
    List<const char*> _newChunks = ListFromArgs<const char*> (newChunks);

    for (int c = 0; c < _chunks.size(); c ++)
    {
        const char* chunk = _chunks[c];
        const char* newChunk = _newChunks[c];

        if (Has (text, chunk))
        {
            Replace (_text, chunk, newChunk);
        }
    }

    return String (_text);
}


List<String> StringHelpers::Split (String s, char delim)
{
    List<String> splittedStr;

    std::stringstream stream (s);

    String buffer;

    while (std::getline (stream, buffer, delim))
    {
        splittedStr.push_back (buffer);
    }

    return splittedStr;
}


List<String> StringHelpers::Split (String s)
{
    return Split (s, ' ');
}



