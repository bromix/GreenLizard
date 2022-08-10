#pragma once
#include "GreenLizard/Platform/Windows.hpp"
#include "GreenLizard/Platform/Kernel32.hpp"
#include "GreenLizard/Platform/Handle.hpp"
#include "GreenLizard/String.hpp"

namespace GreenLizard::IO::Pipes
{
	class NamedPipeClientStream::Impl final
	{
	 public:
		explicit Impl(const String& pipeName)
		{
			this->pipeName = R"(\\.\pipe\)" + pipeName;
		}

		void Connect(const uint32_t timeOut)
		{
			pipeHandle = ::CreateFile(pipeName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0,
				nullptr);
			if (pipeHandle.IsInvalid())
			{
				throw Platform::Win32Exception(Platform::Kernel32::GetLastError());
			}
			::WaitNamedPipe(pipeName.c_str(), timeOut);
		}

		void Write(const void* buffer, const uint32_t offset, const uint32_t length)
		{
			DWORD bytesWritten = 0;
			::WriteFile(pipeHandle, buffer, length, &bytesWritten, nullptr);
		}

	 private:
		String pipeName;
		Platform::Handle pipeHandle;
	};
}