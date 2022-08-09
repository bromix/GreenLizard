#include <GreenLizard/Platform/Win32Exception.hpp>
#include <GreenLizard/Platform/Kernel32.hpp>

namespace GreenLizard::Platform
{

	Win32Exception::Win32Exception(int errorCode) :
		Exception(Kernel32::GetLastErrorMessage(errorCode)),
		errorCode(errorCode)
	{
	}

	int Win32Exception::ErrorCode() const
	{
		return errorCode;
	}
}