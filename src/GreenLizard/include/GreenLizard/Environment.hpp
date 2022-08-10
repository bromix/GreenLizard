#pragma once

#include "String.hpp"

namespace GreenLizard
{
	class Environment final
	{
	 public:
		/**
		 * @brief Default constructor.
		 */
		Environment() = delete;

		/**
		 * @brief Destructor.
		 */
		~Environment() = delete;

		/**
		 * @brief Returns the name of the computer.
		 * @return The name of the computer.
		 */
		[[nodiscard]] static String MachineName();

		static String UserName();
	};
}