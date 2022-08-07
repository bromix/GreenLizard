#pragma once

#include <vector>
#include "Registry.hpp"
#include "GreenLizard/String.hpp"
#include <GreenLizard/Platform/Windows.hpp>
#include <GreenLizard/Ref.hpp>

namespace GreenLizard::Win32
{
	class RegistryKey
	{
	 public:
		RegistryKey(const RegistryKey&) = delete;
		RegistryKey& operator=(const RegistryKey&) = delete;
		RegistryKey(RegistryKey&&) = delete;
		RegistryKey& operator=(RegistryKey&&) = delete;

		RegistryKey(HKEY hKey, RegistryView view);
		static Ref<RegistryKey> OpenBaseKey(RegistryHive hive, RegistryView view = RegistryView::Default);

		std::vector<String> GetSubKeyNames() const;
	 private:
		static void validateRegistryView(RegistryView view);

		HKEY hKey = nullptr;
		RegistryView view;
	};
}