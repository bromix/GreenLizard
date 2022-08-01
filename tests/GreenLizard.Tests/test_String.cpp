//
// Created by mbr on 01/08/2022.
//

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
}

TEST(String, Ctor_char) {
    String name = "GreenLizard";
    ASSERT_FALSE(name.IsNull());
}