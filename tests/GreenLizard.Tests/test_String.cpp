#include <gtest/gtest.h>
#include <GreenLizard/String.hpp>

using namespace GreenLizard;

TEST(String, Ctor_default) {
    String name;
    ASSERT_TRUE(name.IsNull());
}

TEST(String, Ctor_nullptr) {
    String name = nullptr;
    ASSERT_TRUE(name.IsNull());
}

TEST(String, Ctor_nullptr_of_wchar_t) {
    wchar_t *buffer = nullptr;
    String name = buffer;
    ASSERT_TRUE(name.IsNull());
}

TEST(String, Ctor_wchar_t) {
    String name = L"GreenLizard";
    ASSERT_FALSE(name.IsNull());

    ASSERT_EQ(name, "GreenLizard");
    ASSERT_EQ(name, L"GreenLizard");
}

TEST(String, Ctor_char) {
    String name = "GreenLizard";
    ASSERT_FALSE(name.IsNull());

    ASSERT_EQ(name, "GreenLizard");
    ASSERT_EQ(name, L"GreenLizard");
}

TEST(String, Append){
    String name = "Lizard";
    String fullName = "Green " + name;
    ASSERT_EQ(fullName, "Green Lizard");
}