#include <gtest/gtest.h>
#include <GreenLizard/Win32/RegistryKey.hpp>

using namespace GreenLizard::Win32;

TEST(Registry, Ctor)
{
    auto key = RegistryKey::OpenBaseKey(RegistryHive::LocalMachine, RegistryView::Default);
    ASSERT_TRUE(true);
}