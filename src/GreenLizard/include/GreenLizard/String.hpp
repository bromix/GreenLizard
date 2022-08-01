#pragma once

#include <string>
#include <optional>

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
         * @brief The underlying type.
         */
        using UnderlyingType = wchar_t;

        /**
         * @brief Check if the string is null.
         * @return True if the string is null, false otherwise.
         */
        bool IsNull() const;

    private:
        std::optional<std::basic_string<UnderlyingType>> stringBuffer;
    };
}