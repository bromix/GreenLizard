#pragma once

#include "Exception.hpp"

namespace GreenLizard
{
	class Numeric final
	{
	 public:
		Numeric() = delete;
		~Numeric() = delete;

		/**
		 * @brief Cast an integral value to another integral value.
		 * @param value The value to cast.
		 * @param to The type to cast to.
		 * @return The casted value.
		 * @remark This function uses static_assert to check if the cast is valid at compile time.
		 */
		template<typename TTarget, typename TSource>
		static TTarget StrictIntCast(TSource source)
		{
			// Both types must be integral.
			static_assert(std::is_integral<TTarget>::value && std::is_integral<TSource>::value,
				"Both types must be integral.");

			// Both types must be either signed or unsigned.
			static_assert((std::is_signed<TTarget>::value && std::is_signed<TSource>::value)
					|| (std::is_unsigned<TTarget>::value && std::is_unsigned<TSource>::value),
				"Both types must be either signed or unsigned.");


			// target size must be equal or greater than source size
			static_assert(sizeof(TTarget) >= sizeof(TSource), "Target size must be equal or greater than source size.");

			return static_cast<TTarget>(source);
		}

		/**
		 * @brief Cast an floating point value to another floating point value.
		 * @param value The value to cast.
		 * @param to The type to cast to.
		 * @return The casted value.
		 * @remark This function uses static_assert to check if the cast is valid at compile time.
		 */
		template<typename TTarget, typename TSource>
		static TTarget StrictFloatCast(TSource source)
		{
			// Both types must be floating point.
			static_assert(std::is_floating_point<TTarget>::value && std::is_floating_point<TSource>::value,
				"Both types must be floating point.");

			// Both types must be either signed or unsigned.
			static_assert((std::is_signed<TTarget>::value && std::is_signed<TSource>::value)
					|| (std::is_unsigned<TTarget>::value && std::is_unsigned<TSource>::value),
				"Both types must be either signed or unsigned.");


			// target size must be equal or greater than source size
			static_assert(sizeof(TTarget) >= sizeof(TSource), "Target size must be equal or greater than source size.");

			return static_cast<TTarget>(source);
		}

		/**
		 * @brief Cast an arithmetic value to another arithmetic value.
		 * @param value The value to cast.
		 * @param to The type to cast to.
		 * @return The casted value.
		 * @remark This function uses static_assert to check if the cast is valid at compile time.
		 */
		template<typename TTarget, typename TSource>
		static TTarget StrictCast(TSource source)
		{
			// Both types must be arithmetic.
			static_assert(std::is_arithmetic<TTarget>::value && std::is_arithmetic<TSource>::value,
				"Both types must be arithmetic.");

			// Both types must be either signed or unsigned.
			static_assert((std::is_signed<TTarget>::value && std::is_signed<TSource>::value)
					|| (std::is_unsigned<TTarget>::value && std::is_unsigned<TSource>::value),
				"Both types must be either signed or unsigned.");


			// target size must be equal or greater than source size
			static_assert(sizeof(TTarget) >= sizeof(TSource), "Target size must be equal or greater than source size.");

			return static_cast<TTarget>(source);
		}

		/**
		 * @brief Cast an integral value to another integral value.
		 * @param value The value to cast.
		 * @param to The type to cast to.
		 * @return The casted value.
		 * @remark This function casts only to the target type if the numeric value will fit in the target type.
		 * @throws GreenLizard::Exception if the conversion is not valid.
		 */
		template<typename TTarget, typename TSource>
		static TTarget IntCast(TSource source)
		{
			// Both types must be integral.
			static_assert(std::is_integral<TTarget>::value && std::is_integral<TSource>::value,
				"Types must be integral.");

			// use numeric limits to validate if the given type would fit into the target type
			if (source <= std::numeric_limits<TTarget>::max() && source >= std::numeric_limits<TTarget>::min())
			{
				return static_cast<TTarget>(source);
			}

			throw Exception("Value out of range");
		}

		/**
		 * @brief Cast an floating point value to another floating point value.
		 * @param value The value to cast.
		 * @param to The type to cast to.
		 * @return The casted value.
		 * @remark This function casts only to the target type if the numeric value will fit in the target type.
		 * @throws GreenLizard::Exception if the conversion is not valid.
		 */
		template<typename TTarget, typename TSource>
		static TTarget FloatCast(TSource source)
		{
			// Both types must be floating point.
			static_assert(std::is_floating_point<TTarget>::value && std::is_floating_point<TSource>::value,
				"Types must be floating point.");

			// use numeric limits to validate if the given type would fit into the target type
			if (source <= std::numeric_limits<TTarget>::max() && source >= std::numeric_limits<TTarget>::min())
			{
				return static_cast<TTarget>(source);
			}

			throw Exception("Value out of range");
		}

		/**
		 * @brief Cast an arithmetic value to another arithmetic value.
		 * @param value The value to cast.
		 * @param to The type to cast to.
		 * @return The casted value.
		 * @remark This function casts only to the target type if the numeric value will fit in the target type.
		 * @throws GreenLizard::Exception if the conversion is not valid.
		 */
		template<typename TTarget, typename TSource>
		static TTarget Cast(TSource source)
		{
			// types must be arithmetic
			static_assert(std::is_arithmetic<TTarget>::value && std::is_arithmetic<TSource>::value,
				"Types must be arithmetic.");

			// use numeric limits to validate if the given type would fit into the target type
			if (source <= std::numeric_limits<TTarget>::max() && source >= std::numeric_limits<TTarget>::min())
			{
				return static_cast<TTarget>(source);
			}

			throw Exception("Value out of range");
		}
	};
}