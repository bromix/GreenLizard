#include <GreenLizard/Platform/Handle.hpp>

namespace GreenLizard {
    Platform::Handle::Handle(HANDLE const &handle) : handle(handle) {}

    Platform::Handle::operator ::HANDLE() const {
        return this->handle;
    }

    bool Platform::Handle::IsInvalid() const {
        return IsNull() || handle == INVALID_HANDLE_VALUE;
    }

    bool Platform::Handle::IsNull() const {
        return handle == nullptr;
    }
}