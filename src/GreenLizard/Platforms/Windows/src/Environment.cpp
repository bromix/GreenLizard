#include <GreenLizard/Environment.hpp>
#include <GreenLizard/Numeric.hpp>
#include <GreenLizard/Platform/Windows.hpp>

#include <lmcons.h>

namespace GreenLizard
{
	String Environment::MachineName()
	{
		std::wstring buffer(MAX_COMPUTERNAME_LENGTH + 1, L'\0');
		auto size = Numeric::StrictIntCast<DWORD>(buffer.size());
		if (::GetComputerNameW(buffer.data(), &size))
		{
			return buffer.data();
		}
		throw Exception("GetComputerNameW failed");
	}

	String Environment::UserName()
	{
		std::wstring buffer(UNLEN + 1, L'\0');
		auto size = Numeric::StrictIntCast<DWORD>(buffer.size());
		if (::GetUserNameW(buffer.data(), &size))
		{
			// we must subtract 1 because GetUserNameW includes the null terminator
			return buffer.data();
		}

		throw Exception("GetUserNameW failed");
	}

	String Environment::NewLine()
	{
		// initialize only once.
		static auto newLine = String{ "\r\n" };
		return newLine;
	}

	String Environment::CurrentDirectory()
	{
		auto size = ::GetCurrentDirectoryW(0, nullptr);
		if (size == 0)
		{
			throw Exception("GetCurrentDirectoryW failed");
		}
		std::wstring buffer(size, L'\0');
		if (::GetCurrentDirectoryW(size, buffer.data()) == 0)
		{
			throw Exception("GetCurrentDirectoryW failed");
		}

		// we must subtract 1 because GetCurrentDirectoryW includes the null terminator
		return { buffer.data(), size - 1 };
	}
}