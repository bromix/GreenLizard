#pragma once

#include <string>

namespace GreenLizard
{
    class String final
    {
    public:
        String(const char *string);
        String(const std::string &string);

    private:
        std::string _string;
    };
}