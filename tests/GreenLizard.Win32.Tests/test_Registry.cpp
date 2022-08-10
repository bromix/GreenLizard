#include <gtest/gtest.h>
#include <GreenLizard/GreenLizard.hpp>
#include <GreenLizard/Win32/RegistryKey.hpp>

using namespace GreenLizard;
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

TEST(Registry, GetValue)
{
	auto currentUserKey = RegistryKey::OpenBaseKey(RegistryHive::LocalMachine, RegistryView::Default);
	auto softwareKey = currentUserKey->OpenSubKey(R"(SOFTWARE\Microsoft\Windows\CurrentVersion)");
	auto value = softwareKey->GetValue(R"(CommonFilesDir)");
	ASSERT_EQ(value->Kind(), RegistryValueKind::String);
	auto stringValue = value->Value<String>();
	ASSERT_FALSE(stringValue.IsNull());
	ASSERT_FALSE(stringValue.IsEmpty());
}

TEST(Registry, GetStringValue)
{
	auto currentUserKey = RegistryKey::OpenBaseKey(RegistryHive::LocalMachine, RegistryView::Default);
	auto softwareKey = currentUserKey->OpenSubKey(R"(SOFTWARE\Microsoft\Windows\CurrentVersion)");
	auto stringValue = softwareKey->GetStringValue(R"(CommonFilesDir)");
	ASSERT_FALSE(stringValue.IsNull());
	ASSERT_FALSE(stringValue.IsEmpty());
}