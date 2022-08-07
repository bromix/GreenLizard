#pragma once

#include <stdint.h>

namespace GreenLizard::Win32
{
    enum class RegistryView: uint32_t
    {
        Default = 0,
        Registry64 = 0x0100,
        Registry32 = 0x0200
    };

    enum class RegistryHive: uint32_t
    {
        ClassesRoot = 0x80000000,     // HKEY_CLASSES_ROOT
        CurrentUser = 0x80000001,     // HKEY_CURRENT_USER
        LocalMachine = 0x80000002,    // HKEY_LOCAL_MACHINE
        Users = 0x80000003,           // HKEY_USERS
        PerformanceData = 0x80000004, // HKEY_PERFORMANCE_DATA
        CurrentConfig = 0x80000005,   // HKEY_CURRENT_CONFIG
        DynData = 0x80000006,         // HKEY_DYN_DATA
    };
}