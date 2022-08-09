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

TEST(Registry, GetValueKind)
{
	auto currentUserKey = RegistryKey::OpenBaseKey(RegistryHive::LocalMachine, RegistryView::Default);
	auto softwareKey = currentUserKey->OpenSubKey(R"(SOFTWARE\Microsoft\Windows\CurrentVersion)");
	auto valueKind = softwareKey->GetValueKind(R"(CommonFilesDir)");
	ASSERT_EQ(valueKind, RegistryValueKind::String);

	valueKind = softwareKey->GetValueKind(R"(ProgramFilesPath)");
	ASSERT_EQ(valueKind, RegistryValueKind::ExpandString);
}