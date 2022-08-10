#pragma once

#include <GreenLizard/GreenLizard.hpp>

namespace GreenLizard::Platform
{
	class Kernel32 final
	{
	 public:
		Kernel32() = delete;
		~Kernel32() = delete;

		/**
		 * @brief Get the last error code.
		 * @return
		 */
		static uint32_t GetLastError();

		static String GetLastErrorMessage();
		static String GetLastErrorMessage(uint32_t errorCode);
	};
}