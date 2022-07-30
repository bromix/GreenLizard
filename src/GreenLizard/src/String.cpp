#include <GreenLizard/String.hpp>

namespace GreenLizard
{
    String::String(const char *string)
        : _string(string)
    {
    }
    
    String::String(const std::string &string) : _string(string){};
}