#include "../../../Windows.hpp"
#include <GreenLizard/String.hpp>

namespace GreenLizard::IO::Pipes
{
    class NamedPipeClientStream::Impl final
    {
    public:
        explicit Impl(const String &pipeName)
        {
            this->pipeName = "\\\\.\\pipe\\" + pipeName;
        }

        void Connect(const uint32_t timeOut)
        {
            pipeHandle = CreateFile(pipeName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
            WaitNamedPipe(pipeName.c_str(), timeOut);
        }

        void Write(const void *buffer, const uint32_t offset, const uint32_t length)
        {
            DWORD bytesWritten = 0;
            WriteFile(pipeHandle, buffer, length, &bytesWritten, NULL);
        }

    private:
        String pipeName;
        HANDLE pipeHandle = nullptr;
    };
}