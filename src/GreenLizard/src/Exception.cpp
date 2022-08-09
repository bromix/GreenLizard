#include <GreenLizard/Exception.hpp>
#include "Encoding.hpp"

namespace GreenLizard
{
	Exception::Exception(const String& message) : message(message)
	{
	}

	String Exception::Message() const
	{
		return message;
	}

	const char* Exception::what() const
	{
		if (lazyWhat.empty())
		{
			lazyWhat = Encoding::Convert<char, Environment::CharacterType>(message.c_str());
		}
		return lazyWhat.c_str();
	}
}