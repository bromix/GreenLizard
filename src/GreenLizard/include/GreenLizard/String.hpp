#pragma once

#include <string>
#include <optional>

#include "Environment.hpp"

namespace GreenLizard {
    class String final {
    public:
        /**
         * @brief Default constructor.
         */
        String() = default;

        /**
         * @brief Constructor from nullptr.
         */
        String(std::nullptr_t);

        /**
         * @brief Destructor.
         */
        ~String() = default;

        /**
         * @brief Constructor from char*.
         */
        String(const char* string);

        /**
         * @brief Constructor from wchar_t*.
         */
        String(const wchar_t *string);

        /**
         * @brief Check if the string is null.
         * @return True if the string is null, false otherwise.
         */
        bool IsNull() const;

    private:
        class Encoding;
        std::optional<std::basic_string<Environment::CharacterType>> stringBuffer;
    };
}