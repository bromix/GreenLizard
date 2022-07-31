#include <stdexcept>
#include <GreenLizard/IO/Pipes/NamedPipeClientStream.hpp>

#include <Platform/IO/Pipes/NamedPipeClientStreamImpl.hpp>

namespace GreenLizard::IO::Pipes
{
    NamedPipeClientStream::NamedPipeClientStream(const String &pipeName)
    {
        impl = std::make_shared<NamedPipeClientStream::Impl>(pipeName);
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

        impl->Connect(timeOut);
    }

    void NamedPipeClientStream::Write(const void *buffer, const uint32_t offset, const uint32_t length)
    {
        impl->Write(buffer, offset, length);
    }
}