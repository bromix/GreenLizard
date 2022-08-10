#pragma once
#include <GreenLizard/Exception.hpp>

namespace GreenLizard::Platform
{
	class Win32Exception : public Exception
	{
	 public:
		explicit Win32Exception(uint32_t errorCode);

		/**
		 * @brief Get the error code of the exception.
		 * @return The error code of the exception.
		 */
		uint32_t ErrorCode() const;

	 private:
		uint32_t errorCode = 0;
	};
}