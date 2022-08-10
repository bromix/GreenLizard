#include <GreenLizard/Platform/Win32Exception.hpp>
#include <GreenLizard/Platform/Kernel32.hpp>

namespace GreenLizard::Platform
{

	Win32Exception::Win32Exception(uint32_t errorCode) :
		Exception(Kernel32::GetLastErrorMessage(errorCode)),
		errorCode(errorCode)
	{
	}

	uint32_t Win32Exception::ErrorCode() const
	{
		return errorCode;
	}
}