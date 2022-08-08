#include <stdexcept>
#include "GreenLizard/Win32/RegistryKey.hpp"

namespace GreenLizard::Win32
{
	Ref<RegistryKey> Win32::RegistryKey::OpenBaseKey(RegistryHive hive, RegistryView view)
	{
		validateRegistryView(view);

		HKEY hKey = (HKEY)hive;
		return CreateRef<RegistryKey>(hKey, view);
	}

	void RegistryKey::validateRegistryView(RegistryView view)
	{
		if (view != RegistryView::Default && view != RegistryView::Registry64 && view != RegistryView::Registry32)
		{
			// FIXME: use custom exception
			throw std::invalid_argument("Invalid registry view");
		}
	}

	RegistryKey::RegistryKey(HKEY hKey, RegistryView view)
	{
		this->hKey = hKey;
		this->view = view;

	}
	std::vector<String> RegistryKey::GetSubKeyNames() const
	{
		std::vector<String> output;

		DWORD index = 0;
		std::wstring buffer(MAX_PATH, '\0');
		DWORD   bufferSize = buffer.length();
		do
		{
			bufferSize = buffer.length();
			auto status = RegEnumKeyEx(hKey, index, &buffer[0], &bufferSize, nullptr, nullptr, nullptr, nullptr);
			if (status == ERROR_SUCCESS)
			{
				String keyName(buffer.c_str(), bufferSize);
				output.emplace_back(std::move(keyName));
				index++;
				continue;
			}
			else if (status == ERROR_NO_MORE_ITEMS)
			{
				break;
			}
			else
			{
				// FIXME: use custom exception for Win32 GetLastError
			}
		} while (true);
		return output;
	}
}