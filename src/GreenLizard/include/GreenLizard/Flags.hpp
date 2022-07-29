#pragma once

#include <stdarg.h>

// based on https://m-peko.github.io/craft-cpp/posts/different-ways-to-define-binary-flags/

namespace GreenLizard
{
    template <typename TEnum>
    class Flags
    {
        static_assert(std::is_enum_v<TEnum>, "Flags can only be specialized for enum types");

        using TUnderlying = typename std::underlying_type_t<TEnum>;

    public:
        // Flags(TEnum flags) : flags(flags) {}

        // varargs constructor
        template <typename... TEnums>
        Flags(typename TEnums... flags)
        {
            this->flags = ToFlagType(InternalAdd(0, flags...));
        }

        bool Contains(TEnum flag) const
        {
            return (ToUnderlyingType(this->flags) & ToUnderlyingType(flag)) != 0;
        }

        bool operator==(TEnum flag) const
        {
            return ToUnderlyingType(this->flags) == ToUnderlyingType(flag);
        }

        bool operator!=(TEnum flag) const
        {
            return !operator==(flag);
        }

    private:
        static constexpr TUnderlying InternalAdd(typename TUnderlying underlying)
        {
            return underlying;
        }

        template <typename TEnum, typename ...TEnums >
        static constexpr TUnderlying InternalAdd(typename TUnderlying underlying, typename TEnum flag, typename TEnums... flags)
        {
            underlying |= ToUnderlyingType(flag);
            return InternalAdd(underlying, flags...);
        }

        static constexpr TUnderlying ToUnderlyingType(TEnum e)
        {
            return static_cast<TUnderlying>(e);
        }

        static constexpr TEnum ToFlagType(TUnderlying e)
        {
            return static_cast<TEnum>(e);
        }

    private:
        TEnum flags = static_cast<TEnum>(0);
    };
}