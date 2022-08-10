#include <GreenLizard/Win32/RegistryValue.hpp>

namespace GreenLizard::Win32
{
	RegistryValue::RegistryValue(const String& value, RegistryValueKind kind) :
		kind(kind),
		value(value)
	{

	}

	RegistryValueKind RegistryValue::Kind() const
	{
		return this->kind;
	}
}