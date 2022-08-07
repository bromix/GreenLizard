#pragma once

namespace GreenLizard {
    class Encoding final {
    private:
        template<typename TTo, typename TFrom>
        using IsSameEncodingType = std::enable_if_t<std::is_same_v<TTo, TFrom>, bool>;

        template<typename TTo, typename TFrom>
        using IsNotSameEncodingType = std::enable_if_t<!std::is_same_v<TTo, TFrom>, bool>;
    public:
        /**
         * @brief Default constructor.
         */
        Encoding() = delete;

        /**
         * @brief Destructor.
         */
        ~Encoding() = delete;

        template<typename TTo, typename TFrom, IsSameEncodingType<TTo, TFrom> = true>
        static std::basic_string<TTo> Convert(const std::basic_string<TFrom> &input) {
            return std::move(input);
        }

        template<typename TTo, typename TFrom, IsNotSameEncodingType<TTo, TFrom> = true>
        static std::basic_string<TTo> Convert(const std::basic_string<TFrom> &input);
    };
}