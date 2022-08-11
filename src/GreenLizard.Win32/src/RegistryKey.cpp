#include <GreenLizard/Win32/RegistryKey.hpp>
#include <GreenLizard/Platform/Windows.hpp>
#include <stdexcept>
#include "GreenLizard/Numeric.hpp"

namespace GreenLizard::Win32
{
	RegistryKey::~RegistryKey()
	{
		Close();
	}

	Ref<RegistryKey> Win32::RegistryKey::OpenBaseKey(RegistryHive hive, RegistryView view)
	{
		validateRegistryView(view);

		HKEY hKey = (HKEY)hive;
		return CreateRef<RegistryKey>(hKey, view);
	}

	Ref<RegistryKey> RegistryKey::OpenSubKey(const String& subKeyName) const
	{
		HKEY hSubKey = nullptr;
		auto status = ::RegOpenKeyExW(hKey, subKeyName.c_str(), 0, KEY_READ, &hSubKey);
		if (status != ERROR_SUCCESS)
			throw Platform::Win32Exception(status);

		return CreateRef<RegistryKey>(hSubKey, view);
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
		DWORD bufferSize = buffer.length();
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
				throw Platform::Win32Exception(status);
			}
		} while (true);
		return output;
	}

	std::vector<String> RegistryKey::GetValueNames() const
	{
		std::vector<String> output;

		DWORD index = 0;
		std::wstring buffer(MAX_PATH, '\0');
		DWORD bufferSize = buffer.length();
		do
		{
			bufferSize = buffer.length();
			auto status = RegEnumValueW(hKey, index, &buffer[0], &bufferSize, nullptr, nullptr, nullptr, nullptr);
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
				throw Platform::Win32Exception(status);
			}
		} while (true);
		return output;
	}

	void RegistryKey::Close()
	{
		// Don't close system keys.
		if (IsSystemKey(*this))
			return;

		if (hKey != nullptr)
		{
			auto status = ::RegCloseKey(hKey);
			if (status != ERROR_SUCCESS)
				throw Platform::Win32Exception(status);
			hKey = nullptr;
		}
	}

	bool RegistryKey::IsSystemKey(const RegistryKey& key)
	{
		// return true if the key is a system key.
		return key.hKey == HKEY_CLASSES_ROOT ||
			key.hKey == HKEY_CURRENT_USER ||
			key.hKey == HKEY_LOCAL_MACHINE ||
			key.hKey == HKEY_USERS ||
			key.hKey == HKEY_PERFORMANCE_DATA ||
			key.hKey == HKEY_PERFORMANCE_TEXT ||
			key.hKey == HKEY_PERFORMANCE_NLSTEXT ||
			key.hKey == HKEY_CURRENT_CONFIG ||
			key.hKey == HKEY_DYN_DATA ||
			key.hKey == HKEY_CURRENT_USER_LOCAL_SETTINGS;
	}

	Ref<RegistryValue> RegistryKey::GetValue(const String& valueName) const
	{
		// get the value kind and value via RegQueryValueExW.
		DWORD type = 0;
		DWORD size = 0;
		auto status = ::RegQueryValueExW(hKey, valueName.c_str(), nullptr, &type, nullptr, &size);
		if (status != ERROR_SUCCESS)
			throw Platform::Win32Exception(status);

		// allocate a buffer for the value.
		std::vector<BYTE> buffer(size);
		status = ::RegQueryValueExW(hKey, valueName.c_str(), nullptr, &type, buffer.data(), &size);
		if (status != ERROR_SUCCESS)
			throw Platform::Win32Exception(status);

		// return std::string of buffer is type is String
		if (type == REG_SZ)
		{
			String stringValue(reinterpret_cast<const wchar_t*>(buffer.data()), size / sizeof(wchar_t));
			return CreateRef<RegistryValue>(std::move(stringValue), RegistryValueKind::String);
		}
		else if (type == REG_EXPAND_SZ)
		{
			String stringValue(reinterpret_cast<const wchar_t*>(buffer.data()), size / sizeof(wchar_t));
			return CreateRef<RegistryValue>(std::move(stringValue), RegistryValueKind::ExpandString);
		}
		else if (type == REG_MULTI_SZ)
		{
			String stringValue(reinterpret_cast<const wchar_t*>(buffer.data()), size / sizeof(wchar_t));
			return CreateRef<RegistryValue>(std::move(stringValue), RegistryValueKind::MultiString);
		}
		else if (type == REG_DWORD)
		{
			auto intValue = Numeric::StrictIntCast<uint32_t>(*reinterpret_cast<const DWORD32*>(buffer.data()));
			return CreateRef<RegistryValue>(intValue);
		}
		else if (type == REG_QWORD)
		{
			auto intValue = Numeric::StrictIntCast<uint64_t>(*reinterpret_cast<const DWORD64*>(buffer.data()));
			return CreateRef<RegistryValue>(intValue);
		}
//		else if (type == REG_BINARY)
//			return RegistryValue(RegistryValueKind::Binary, buffer);
//		else if (type == REG_NONE)
//			return RegistryValue(RegistryValueKind::None, String());
//		else
//

		throw std::invalid_argument("Invalid registry value kind");
	}

	String RegistryKey::GetStringValue(const String& valueName) const
	{
		auto value = GetValue(valueName);
		auto valueKind = value->Kind();
		if (valueKind == RegistryValueKind::String || valueKind == RegistryValueKind::ExpandString
			|| valueKind == RegistryValueKind::MultiString)
		{
			return value->Value<String>();
		}

		throw std::invalid_argument("Registry value is not a string");
	}
}