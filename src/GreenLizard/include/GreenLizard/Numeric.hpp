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
		 * @brief SafeCast cast of a value from one type to another.
		 * @tparam T The target type.
		 * @tparam U The source type.
		 * @param u The source value.
		 * @return The target value.
		 */
		template<typename TTarget, typename TSource>
		static TTarget SafeCast(TSource source)
		{
			// types must be arithmetic
			static_assert(std::is_arithmetic<TTarget>::value && std::is_arithmetic<TSource>::value,
				"Types must be arithmetic.");

			// Source and target must be either signed or unsigned
			static_assert(
				std::is_signed<TTarget>::value && std::is_signed<TSource>::value ||
					std::is_unsigned<TTarget>::value && std::is_unsigned<TSource>::value,
				"Target and source must be both either signed or unsigned.");


			// target size must be equal or greater than source size
			static_assert(sizeof(TTarget) >= sizeof(TSource), "Target size must be equal or greater than source size.");

			return static_cast<TTarget>(source);
		}

		/**
		 * @brief SafeCast cast of a value from one type to another.
		 * @tparam T The target type.
		 * @tparam U The source type.
		 * @param u The source value.
		 * @return The target value.
		 */
		template<typename TTarget, typename TSource>
		static TTarget FitCast(TSource source)
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