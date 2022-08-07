#pragma once

#include <GreenLizard/Ref.hpp>
#include "Registry.hpp"

namespace GreenLizard::Win32
{
	class RegistryKey
	{
	 public:
		static Ref<RegistryKey> OpenBaseKey(RegistryHive hive, RegistryView view = RegistryView::Default);

	 private:
		static void validateRegistryView(RegistryView view);
	};
}