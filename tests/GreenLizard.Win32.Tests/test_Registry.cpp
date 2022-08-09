#include <gtest/gtest.h>
#include <GreenLizard/Win32/RegistryKey.hpp>

using namespace GreenLizard::Win32;

TEST(Registry, GetSubKeyNames)
{
    auto key = RegistryKey::OpenBaseKey(RegistryHive::CurrentUser, RegistryView::Default);

	auto keyNames = key->GetSubKeyNames();
	ASSERT_FALSE(keyNames.empty());
}

TEST(Registry, OpenSubKey)
{
	auto currentUserKey = RegistryKey::OpenBaseKey(RegistryHive::CurrentUser, RegistryView::Default);
	auto softwareKey = currentUserKey->OpenSubKey("Software");
	auto keyNames = softwareKey->GetSubKeyNames();
	ASSERT_FALSE(keyNames.empty());
}

TEST(Registry, GetValueNames)
{
	auto currentUserKey = RegistryKey::OpenBaseKey(RegistryHive::CurrentUser, RegistryView::Default);
	auto softwareKey = currentUserKey->OpenSubKey(R"(Software\Microsoft)");
	auto valueNames = softwareKey->GetValueNames();
	ASSERT_FALSE(valueNames.empty());
}