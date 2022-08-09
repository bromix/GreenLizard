#pragma once
#include <GreenLizard/Exception.hpp>

namespace GreenLizard::Platform
{
	class Win32Exception : public Exception
	{
	 public:
		explicit Win32Exception(int errorCode);

		/**
		 * @brief Get the error code of the exception.
		 * @return The error code of the exception.
		 */
		int ErrorCode() const;

	 private:
		int errorCode = 0;
	};
}