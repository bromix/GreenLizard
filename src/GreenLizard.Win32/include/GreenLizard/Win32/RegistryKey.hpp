#pragma once

#include <vector>
#include "Registry.hpp"
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

		static bool IsSystemKey(const RegistryKey& key);

		/**
		 * @brief Get the sub key names.
		 * @return The sub key names.
		 */
		std::vector<String> GetSubKeyNames() const;
	 private:

		static void validateRegistryView(RegistryView view);

		HKEY hKey = nullptr;
		RegistryView view;
	};
}