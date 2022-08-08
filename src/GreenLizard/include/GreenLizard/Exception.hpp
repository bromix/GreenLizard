#pragma once

#include <exception>
#include "String.hpp"

namespace GreenLizard
{
	class Exception : public std::exception
	{
	 public:
		explicit Exception(const String& message);

		const char* what() const override;
		String Message() const;
	 private:
		String message;
		mutable std::string lazyWhat;
	};
}