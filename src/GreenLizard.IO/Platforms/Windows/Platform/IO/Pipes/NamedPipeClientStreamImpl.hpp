#include "../../../Win32.hpp"
#include <GreenLizard/String.hpp>

namespace GreenLizard::IO::Pipes
{
    class NamedPipeClientStream::Impl final
    {
    public:
        explicit NamedPipeClientStream::Impl(const String &pipeName)
        {
        }

        void Connect(const uint32_t timeOut)
        {
            pipeHandle = CreateFileA("\\\\.\\pipe\\ashampoo-connect-service-hub", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
            WaitNamedPipeA("\\\\.\\pipe\\ashampoo-connect-service-hub", timeOut);
        }

    private:
        HANDLE pipeHandle = nullptr;
    };
}