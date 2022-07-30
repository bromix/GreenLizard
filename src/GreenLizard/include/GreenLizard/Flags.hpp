#pragma once

#include <numeric>
#include <algorithm>

// based on https://m-peko.github.io/craft-cpp/posts/different-ways-to-define-binary-flags/

namespace GreenLizard
{
    template <typename TEnum>
    class Flags
    {
        static_assert(std::is_enum_v<TEnum>, "Flags can only be specialized for enum types");

        using TUnderlying = typename std::underlying_type_t<TEnum>;

    public:
        Flags() = delete;

        template <typename TEnum, typename... TEnums>
        Flags(TEnum flag, TEnums &&...flags)
        {
            auto flagsIterator = {flag, flags...};
            _flags = ToFlagType(std::accumulate(flagsIterator.begin(), flagsIterator.end(), static_cast<TUnderlying>(0), [](TUnderlying &flags, TEnum flag)
                                                {
                flags |= static_cast<TUnderlying>(flag);
                return flags; }));
        }

        /**
         * @brief Adds one or more flags to the current flags
         * 
         * @tparam TEnum 
         * @tparam TEnums 
         * @param flag 
         * @param flags 
         * @return Flags& 
         */
        template <typename TEnum, typename... TEnums>
        Flags &Add(TEnum flag, TEnums &&...flags)
        {
            auto flagsIterator = {flag, flags...};
            _flags = ToFlagType(std::accumulate(flagsIterator.begin(), flagsIterator.end(), static_cast<TUnderlying>(_flags), [](TUnderlying &flags, TEnum flag)
                                                {
                flags |= static_cast<TUnderlying>(flag);
                return flags; }));
            return *this;
        }

        /**
         * @brief Removes one or more flags from the current flags
         * 
         * @tparam TEnum 
         * @tparam TEnums 
         * @param flag 
         * @param flags 
         * @return Flags& 
         */
        template <typename TEnum, typename... TEnums>
        Flags &Remove(TEnum flag, TEnums &&...flags)
        {
            auto flagsIterator = {flag, flags...};
            _flags = ToFlagType(std::accumulate(flagsIterator.begin(), flagsIterator.end(), static_cast<TUnderlying>(_flags), [](TUnderlying &flags, TEnum flag)
                                                {
                flags &= ~static_cast<TUnderlying>(flag);
                return flags; }));
            return *this;
        }

        /**
         * @brief Determines if the given flag is set.
         *
         * @param flag The flag to check.
         * @return true if the flag is set, false otherwise.
         */
        bool Contains(TEnum flag) const
        {
            return (ToUnderlyingType(_flags) & ToUnderlyingType(flag)) != 0;
        }

        /**
         * @brief Determine if any of the given flags are set.
         *
         * @tparam TEnums
         * @param flags The flags to check.
         * @return true if any of the flags are set, false otherwise.
         */
        template<typename ...TEnums>
        bool AnyOf(TEnums&&... flags) const
        {
            auto flagsIterator = {flags...};
            return std::any_of(flagsIterator.begin(), flagsIterator.end(), [this](auto flag)
                               { return Contains(flag); });
        }

        /**
         * @brief Determine if all of the given flags are set.
         * 
         * @tparam TEnums 
         * @param flags The flags to check.
         * @return true if all of the flags are set, false otherwise.
         */
        template<typename ...TEnums>
        bool AllOf(TEnums&&... flags) const
        {
            auto flagsIterator = {flags...};
            return std::all_of(flagsIterator.begin(), flagsIterator.end(), [this](auto flag)
                               { return Contains(flag); });
        }

        bool operator==(TEnum flag) const
        {
            return ToUnderlyingType(_flags) == ToUnderlyingType(flag);
        }

        bool operator!=(TEnum flag) const
        {
            return !operator==(flag);
        }

        operator TUnderlying() const
        {
            return ToUnderlyingType(_flags);
        }

    private:
        static constexpr TUnderlying ToUnderlyingType(TEnum e)
        {
            return static_cast<TUnderlying>(e);
        }

        static constexpr TEnum ToFlagType(TUnderlying e)
        {
            return static_cast<TEnum>(e);
        }

    private:
        TEnum _flags = static_cast<TEnum>(0);
    };
}