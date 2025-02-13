#include <Log.hpp>


const char* Log::DEFAULT_DEBUG_TAG = "[DEBUG]";
const char* Log::DEFAULT_ERROR_TAG = "[ERROR]";
const char* Log::DEFAULT_INFO_TAG = "[INFO]";
const char* Log::DEFAULT_WARNING_TAG = "[WARNING]";


void Log::d (const char* message)
{
    std::cout << DEFAULT_DEBUG_TAG << " " << message << std::endl;
}


void Log::d (const char* message, Args<const char*> params)
{
    String _message = String (message);
    List<const char*> _params = ListFromArgs<const char*> (params);

    
}


void Log::e (const char* message)
{
    std::cerr << DEFAULT_ERROR_TAG << " " << message << std::endl;
}


void Log::ec (const char* error, const char* cause)
{
    e (error);

    std::cerr << "[CAUSE]: " << cause << std::endl;
    std::cerr << std::endl;
}


void Log::i (const char* message)
{
    std::cout << DEFAULT_INFO_TAG << " " << message << std::endl;
}


void Log::i (const char* message, Args<const char*> params)
{
    
}


void Log::w (const char* message)
{
    std::cout << DEFAULT_WARNING_TAG << " " << message << std::endl;
}


void Log::w (const char* message, Args<const char*> params)
{
    
}

