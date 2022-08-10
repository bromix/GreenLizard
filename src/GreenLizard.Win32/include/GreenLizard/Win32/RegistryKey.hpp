#pragma once

#include <vector>
#include "RegistryTypes.hpp"
#include "RegistryValue.hpp"
#include "GreenLizard/GreenLizard.hpp"
#include <GreenLizard/Platform/Windows.hpp>

namespace GreenLizard::Win32
{
	class RegistryKey
	{
	 public:
		RegistryKey(const RegistryKey&) = delete;
		RegistryKey& operator=(const RegistryKey&) = delete;
		RegistryKey(RegistryKey&&) = delete;
		RegistryKey& operator=(RegistryKey&&) = delete;

		/**
		 * @brief Construct a new Registry Key object.
		 * @param hKey The registry key handle.
		 * @param view The registry view.
		 * @remark use RegistryKey::OpenBaseKey to open a registry key.
		 */
		RegistryKey(HKEY hKey, RegistryView view);

		/**
		 * @brief Destructor.
		 */
		~RegistryKey();

		/**
		 * @brief Close the registry key.
		 */
		void Close();

		/**
		 * @brief Open a base key.
		 * @param hive The hive to open.
		 * @param view The view to open.
		 * @return The opened key.
		 */
		static Ref<RegistryKey> OpenBaseKey(RegistryHive hive, RegistryView view = RegistryView::Default);

		/**
		 * @brief Opens a sub key.
		 * @param subKey The name or path of the sub key to open as read-only.
		 */
		[[nodiscard]] Ref<RegistryKey> OpenSubKey(const String& subKeyName) const;

		[[nodiscard]] Ref<RegistryValue> GetValue(const String& valueName) const;

		[[nodiscard]] String GetStringValue(const String& valueName) const;

		/**
		 * @brief Determine if the registry key is a system key.
		 * @return True if the registry key is a system key, false otherwise.
		 */
		static bool IsSystemKey(const RegistryKey& key);

		/**
		 * @brief Get the sub key names.
		 * @return The sub key names.
		 */
		[[nodiscard]] std::vector<String> GetSubKeyNames() const;

		/**
		 * @brief Get the value names.
		 * @return The value names.
		 */
		[[nodiscard]] std::vector<String> GetValueNames() const;

	 private:

		static void validateRegistryView(RegistryView view);

		HKEY hKey = nullptr;
		RegistryView view;
	};
}