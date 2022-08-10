#include <GreenLizard/Win32/RegistryValue.hpp>

namespace GreenLizard::Win32
{
	RegistryValue::RegistryValue(uint32_t value) :
		kind(RegistryValueKind::DWord),
		value(value)
	{

	}

	RegistryValue::RegistryValue(uint64_t value) :
		kind(RegistryValueKind::QWord),
		value(value)
	{

	}

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