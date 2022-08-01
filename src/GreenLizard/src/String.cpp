#include <GreenLizard/String.hpp>

namespace GreenLizard {
    String::String(std::nullptr_t) {}

    String::String(const char *string) {
        if (string != nullptr) {
            // TODO: convert to UnderlyingType
        }
    }

    String::String(const wchar_t *string) {
        if (string != nullptr) {
            this->stringBuffer = string;
        }
    }

    bool String::IsNull() const {
        return stringBuffer.has_value() == false;
    }

}