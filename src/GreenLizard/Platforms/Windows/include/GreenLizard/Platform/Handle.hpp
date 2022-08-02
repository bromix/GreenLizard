#pragma once

#include "Windows.hpp"

namespace GreenLizard::Platform {
    class Handle {
    public:
        Handle() = default;

        Handle(const ::HANDLE &handle);

        [[nodiscard]] bool IsInvalid() const;

        [[nodiscard]] bool IsNull() const;

        operator ::HANDLE() const;

    private:
        ::HANDLE handle = nullptr;
    };
}