#include <GreenLizard/Platform/Kernel32.hpp>
#include <GreenLizard/Platform/Windows.hpp>

namespace GreenLizard::Platform
{
	uint32_t Kernel32::GetLastError()
	{
		return ::GetLastError();
	}

	String Kernel32::GetLastErrorMessage()
	{
		return GetLastErrorMessage(GetLastError());
	}

	String Kernel32::GetLastErrorMessage(uint32_t errorCode)
	{
		/*
		 * Based on: https://docs.microsoft.com/en-us/windows/win32/debug/retrieving-the-last-error-code
		 */

		std::wstring buffer(2048, L'\0');
		auto size = FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			errorCode,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			&buffer[0],
			buffer.size(),
			nullptr);

		return { buffer.data(), size };
	}
}