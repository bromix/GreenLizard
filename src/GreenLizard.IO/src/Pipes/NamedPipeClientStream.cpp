#include <stdexcept>
#include <GreenLizard/IO/Pipes/NamedPipeClientStream.hpp>

namespace GreenLizard::IO::Pipes
{
    NamedPipeClientStream::NamedPipeClientStream(const String &pipeName)
    {
    }

    void NamedPipeClientStream::Connect()
    {
        Connect(-1);
    }

    void NamedPipeClientStream::Connect(const uint32_t timeOut)
    {
        if (timeOut < 0 && timeOut != -1)
        {
            throw std::invalid_argument("timeOut");
        }

        //ConnectInternal(timeout, CancellationToken.None, Environment.TickCount);
    }
}