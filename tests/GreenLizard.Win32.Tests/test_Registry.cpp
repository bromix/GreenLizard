#include <gtest/gtest.h>
#include <GreenLizard/Win32/RegistryKey.hpp>

using namespace GreenLizard::Win32;

TEST(Registry, GetSubKeyNames)
{
    auto key = RegistryKey::OpenBaseKey(RegistryHive::CurrentUser, RegistryView::Default);

	auto keyNames = key->GetSubKeyNames();
	ASSERT_FALSE(keyNames.empty());
}