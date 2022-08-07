#include <stdexcept>
#include "GreenLizard/Win32/RegistryKey.hpp"

namespace GreenLizard::Win32
{
	Ref<RegistryKey> Win32::RegistryKey::OpenBaseKey(RegistryHive hive, RegistryView view)
	{
		validateRegistryView(view);
		return nullptr;
	}

	void RegistryKey::validateRegistryView(RegistryView view)
	{
		if (view != RegistryView::Default && view != RegistryView::Registry64 && view != RegistryView::Registry32)
		{
			// FIXME: use custom exception
			throw std::invalid_argument("Invalid registry view");
		}
	}
}