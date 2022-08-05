#include <gtest/gtest.h>
#include <GreenLizard/Platform/Handle.hpp>

using namespace GreenLizard;

TEST(Handle, Ctor_default) {
    Platform::Handle handle;
    ASSERT_TRUE(handle.IsNull());
    ASSERT_FALSE(handle.IsInvalid());
    ASSERT_TRUE(handle.IsNullOrInvalid());
}

TEST(Handle, Ctor_nullptr) {
    Platform::Handle handle = nullptr;
    ASSERT_TRUE(handle.IsNull());
    ASSERT_FALSE(handle.IsInvalid());
    ASSERT_TRUE(handle.IsNullOrInvalid());
}

TEST(Handle, Ctor_InvalidHandle) {
    Platform::Handle handle = INVALID_HANDLE_VALUE;
    ASSERT_FALSE(handle.IsNull());
    ASSERT_TRUE(handle.IsInvalid());
}

TEST(Handle, Ctor_ValidHandle) {
    Platform::Handle handle = reinterpret_cast<HANDLE const>(100);
    ASSERT_FALSE(handle.IsInvalid());
    ASSERT_FALSE(handle.IsNull());
}