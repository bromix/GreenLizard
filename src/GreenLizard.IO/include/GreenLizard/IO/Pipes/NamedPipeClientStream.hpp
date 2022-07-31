#pragma once

#include <GreenLizard/String.hpp>

namespace GreenLizard::IO::Pipes
{
    class NamedPipeClientStream final
    {
    public:
        explicit NamedPipeClientStream(const String &pipeName);
    };
}