#pragma once

#include "Win32.hpp"

namespace GreenLizard::Win32
{
    enum class RegistryView
    {
        Default = 0,                  // 0x0000 operate on the default registry view
        Registry64 = KEY_WOW64_64KEY, // 0x0100 operate on the 64-bit registry view
        Registry32 = KEY_WOW64_32KEY, // 0x0200 operate on the 32-bit registry view
    };
}