#pragma once

#include <GreenLizard/GreenLizard.hpp>
#include "RegistryTypes.hpp"
#include <variant>

namespace GreenLizard::Win32
{
	class RegistryValue
	{
	 public:
		RegistryValue(const String& value, RegistryValueKind kind);

		/**
		 * @brief Returns the registry value kind.
		 * @return The registry value kind.
		 */
		[[nodiscard]] RegistryValueKind Kind() const;

		/**
		 * @brief Returns the registry value data.
		 * @return The registry value data.
		 */
		template<typename T>
		T Value() const
		{
			return std::get<T>(value);
		}
	 private:
		RegistryValueKind kind = RegistryValueKind::Unknown;
		std::variant<String> value;
	};
}