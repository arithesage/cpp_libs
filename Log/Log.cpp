#include <Log.hpp>

#include <StringHelpers.hpp>


const char* Log::DEFAULT_DEBUG_TAG = "[DEBUG]";
const char* Log::DEFAULT_ERROR_TAG = "[ERROR]";
const char* Log::DEFAULT_INFO_TAG = "[INFO]";
const char* Log::DEFAULT_WARNING_TAG = "[WARNING]";


const char * Log::replacePlaceholders (const char* message, 
                                       Args<const char*> params)
{
    String _message (message);
    List<const char*> _params = ListFromArgs<const char*> (params);

    for (int p = 0; p < _params.size(); p ++)
    {
        const char* placeholder = StringHelpers::Concat ({
            "${", 
            StringHelpers::IntToStr (p), 
            "}"
        }).c_str ();

        if (StringHelpers::Has (message, placeholder))
        {
            StringHelpers::Replace (message, placeholder, _params[p]);
        }
    }
}


void Log::d (const char* message)
{
    std::cout << DEFAULT_DEBUG_TAG << " " << message << std::endl;
}


void Log::d (const char* message, Args<const char*> params)
{
    std::cout << DEFAULT_DEBUG_TAG << " ";
    std::cout << replacePlaceholders (message, params) << std::endl;
}


void Log::e (const char* error)
{
    std::cerr << DEFAULT_ERROR_TAG << " " << error << std::endl;
}


void Log::e (const char* error, Args<const char*> params)
{
    std::cerr << DEFAULT_ERROR_TAG << " ";
    std::cerr << replacePlaceholders (error, params) << std::endl;
}


void Log::ec (const char* error, const char* cause)
{
    e (error);

    std::cerr << "[CAUSE]: " << cause << std::endl;
    std::cerr << std::endl;
}


void Log::ec (const char* error, Args<const char*> params, 
                                 const char* cause)
{
    e (error, params);

    std::cerr << "[CAUSE]: " << cause << std::endl;
    std::cerr << std::endl;
}


void Log::i (const char* message)
{
    std::cout << DEFAULT_INFO_TAG << " " << message << std::endl;
}


void Log::i (const char* message, Args<const char*> params)
{
    std::cout << DEFAULT_INFO_TAG << " ";
    std::cout << replacePlaceholders (message, params) << std::endl;
}


void Log::w (const char* message)
{
    std::cout << DEFAULT_WARNING_TAG << " " << message << std::endl;
}


void Log::w (const char* message, Args<const char*> params)
{
    std::cout << DEFAULT_WARNING_TAG << " ";
    std::cout << replacePlaceholders (message, params) << std::endl;
}

