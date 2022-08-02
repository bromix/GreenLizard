#include <utility>
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

    Platform::Handle &Platform::Handle::operator=(Platform::Handle &&other) {
        if (!this->IsNull()) {
            // TODO: this is not allowed
        }
        std::swap(this->handle, other.handle);
        return *this;
    }

    Platform::Handle &Platform::Handle::operator=(HANDLE const &other) {
        if (!this->IsNull()) {
            // TODO: this is not allowed
        }
        this->handle = other;
        return *this;
    }

    Platform::Handle::~Handle() {
        if (!this->IsNull()) {
            // TODO: throw exception if not null
            // Caller should close or detach the handle!
        }
    }
}