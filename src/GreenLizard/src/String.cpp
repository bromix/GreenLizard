#include <GreenLizard/String.hpp>
#include "Encoding.hpp"

namespace GreenLizard {
    String::String(std::nullptr_t) {}

    String::String(const char *string) {
        if (string != nullptr) {
            std::basic_string<char> buffer(string);
            this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(buffer);
        }
    }

    String::String(const wchar_t *string) {
        if (string != nullptr) {
            std::basic_string<wchar_t> buffer(string);
            this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(buffer);
        }
    }

    bool String::IsNull() const {
        return stringBuffer.has_value() == false;
    }

    bool String::operator==(const String &other) const {
        return stringBuffer.value() == other.stringBuffer.value();
    }

    bool String::operator!=(const String &other) const {
        return operator==(other) == false;
    }

    String String::Prepend(const String &other) const {
        auto result = other.stringBuffer.value() + stringBuffer.value();
        return String(std::move(result));
    }

    String::String(std::basic_string<Environment::CharacterType> &&string) {
        this->stringBuffer = GreenLizard::Encoding::Convert<Environment::CharacterType>(string);
    }

    String operator+(const String &lhs, const String &rhs) {
        return rhs.Prepend(lhs);
    }
}