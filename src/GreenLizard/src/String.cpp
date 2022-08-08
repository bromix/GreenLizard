#include <GreenLizard/String.hpp>
#include "Encoding.hpp"

namespace GreenLizard
{
	String::String(std::nullptr_t)
	{
	}

	String::String(const char* string)
	{
		if (string != nullptr)
		{
			std::basic_string<char> buffer(string);
			this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(buffer);
		}
	}

	String::String(const char* string, size_t length)
	{
		if (string != nullptr)
		{
			std::basic_string<char> buffer(string, length);
			this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(buffer);
		}
	}

	String::String(const wchar_t* string)
	{
		if (string != nullptr)
		{
			std::basic_string<wchar_t> buffer(string);
			this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(buffer);
		}
	}

	String::String(const wchar_t* string, size_t length)
	{
		if (string != nullptr)
		{
			std::basic_string<wchar_t> buffer(string, length);
			this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(buffer);
		}
	}

	String::String(std::basic_string<Environment::CharacterType>&& string)
	{
		this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(string);
	}

	String::String(const String& other) : stringBuffer(other.stringBuffer)
	{
	}

	String& String::operator=(const String& other)
	{
		this->stringBuffer = other.stringBuffer;
		return *this;
	}

	String::String(String&& other) noexcept: stringBuffer(std::move(other.stringBuffer))
	{
	}

	String& String::operator=(String&& other) noexcept
	{
		stringBuffer = std::move(other.stringBuffer);
		return *this;
	}

	bool String::IsNull() const
	{
		return !stringBuffer.has_value();
	}

	bool String::operator==(const String& other) const
	{
		return stringBuffer.value() == other.stringBuffer.value();
	}

	bool String::operator!=(const String& other) const
	{
		return !operator==(other);
	}

	String String::Prepend(const String& other) const
	{
		auto result = other.stringBuffer.value() + stringBuffer.value();
		return std::move(result);
	}

	const Environment::CharacterType* String::c_str() const
	{
		return stringBuffer.value().c_str();
	}

	bool String::IsEmpty()
	{
		return stringBuffer.value().empty();
	}

	String operator+(const String& lhs, const String& rhs)
	{
		return rhs.Prepend(lhs);
	}
}