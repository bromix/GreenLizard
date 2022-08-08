#include <string>

#include <GreenLizard/Platform/Windows.hpp>
#include "../../../src/Encoding.hpp"

namespace GreenLizard
{
	template<>
	std::basic_string<wchar_t> Encoding::Convert(const std::basic_string<char>& input)
	{
		constexpr DWORD kFlags = MB_ERR_INVALID_CHARS;
		const int utf8Length = static_cast<int>(input.length());
		const int utf16Length = ::MultiByteToWideChar(
			CP_UTF8,    // Source string is in UTF-8
			kFlags,     // Conversion flags
			input.data(),      // Source UTF-8 string pointer
			utf8Length, // Length of the source UTF-8 string, in chars
			nullptr,    // Unused - no conversion done in this step
			0           // Request size of destination buffer, in wchar_ts
		);

		if (utf16Length == 0)
		{
			// Conversion error: capture error code and throw
			const DWORD error = ::GetLastError();
			// throw Utf8ConversionException(
			//     "Cannot get result string length when converting "
			//     "from UTF-8 to UTF-16 (MultiByteToWideChar failed).",
			//     error);
		}

		std::basic_string<wchar_t> utf16(utf16Length, L'\0');

		int result = ::MultiByteToWideChar(
			CP_UTF8,    // Source string is in UTF-8
			kFlags,     // Conversion flags
			input.data(),      // Source UTF-8 string pointer
			utf8Length, // Length of source UTF-8 string, in chars
			utf16.data(),      // Pointer to destination buffer
			utf16Length // Size of destination buffer, in wchar_ts
		);

		if (result == 0)
		{
			// Conversion error: capture error code and throw
			const DWORD error = ::GetLastError();
			// throw Utf8ConversionException(
			//     "Cannot convert from UTF-8 to UTF-16 "
			//     "(MultiByteToWideChar failed).",
			//     error);
		}

		return utf16;
	}

	template<>
	std::basic_string<char> Encoding::Convert(const std::basic_string<wchar_t>& input)
	{
		// constexpr DWORD kFlags = MB_ERR_INVALID_CHARS;
		const int utf16Length = static_cast<int>(input.length());
		const int utf8Length = ::WideCharToMultiByte(
			CP_UTF8,
			0,
			input.data(),
			utf16Length,
			nullptr,
			0,
			nullptr,
			nullptr);

		if (utf8Length == 0)
		{
			// Conversion error: capture error code and throw
			const DWORD error = ::GetLastError();
			// throw Utf8ConversionException(
			//     "Cannot get result string length when converting "
			//     "from UTF-8 to UTF-16 (MultiByteToWideChar failed).",
			//     error);
		}

		std::basic_string utf8(utf8Length, '\0');

		int result = ::WideCharToMultiByte(
			CP_UTF8,     // Source string is in UTF-8
			0,           // Conversion flags
			input.data(),       // Source UTF-8 string pointer
			utf16Length, // Length of source UTF-8 string, in chars
			utf8.data(),        // Pointer to destination buffer
			utf8Length,  // Size of destination buffer, in wchar_ts
			nullptr,
			nullptr);

		if (result == 0)
		{
			// Conversion error: capture error code and throw
			const DWORD error = ::GetLastError();
			// throw Utf8ConversionException(
			//     "Cannot convert from UTF-8 to UTF-16 "
			//     "(MultiByteToWideChar failed).",
			//     error);
		}

		return utf8;
	}
}