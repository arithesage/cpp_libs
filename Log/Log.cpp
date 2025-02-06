#include <Log.hpp>


// Write DEBUG messages.
// For appending int, float and boolean values, use the iS, fS and bS functions.
void Log::d (String message)
{
    std::cout << "[DEBUG] " << message << std::endl;
}


// Write ERROR messages.
// For appending int, float and boolean values, use the iS, fS and bS functions.
void Log::e (String message)
{
    std::cerr << "[ERROR] " << message << std::endl;
}


// Write INFO messages.
// For appending int, float and boolean values, use the iS, fS and bS functions.
void Log::i (String message)
{
    std::cout << "[INFO] " << message << std::endl;
}


// Write WARNING messages.
// For appending int, float and boolean values, use the iS, fS and bS functions.
void Log::w (String message)
{
    std::cerr << "[WARNING] " << message << std::endl;
}
