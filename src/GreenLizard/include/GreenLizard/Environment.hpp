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
		static String MachineName();

		/**
		 * @brief Returns the name of the user.
		 * @return The name of the user.
		 */
		static String UserName();

		/**
		 * @brief Returns the new line character.
		 * @return The new line character.
		 */
		static String NewLine();

		static String CurrentDirectory();
	};
}