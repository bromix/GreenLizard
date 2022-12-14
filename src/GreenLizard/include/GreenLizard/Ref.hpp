#pragma once

#include <memory>

namespace GreenLizard
{
	// Credits go to TheCherno and the Hazel Engine.
	// Taken from https://github.com/TheCherno/Hazel/blob/49da3c1e08245feb5b978269119f50b0873dc9d1/Hazel/src/Hazel/Core/Base.h#L38

	/**
	 * @brief A reference counted smart pointer.
	 * @tparam T The type of the object to reference.
	 */
	template<typename T>
	using Ref = std::shared_ptr<T>;

	/**
	 * @brief Creates a reference counted smart pointer.
	 * @tparam T The type of the object to reference.
	 * @param args The arguments to pass to the constructor of the object.
	 * @return A reference counted smart pointer to the new object.
	 */
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	/**
	 * @brief A unique reference counted smart pointer.
	 * @tparam T The type of the object to reference.
	 */
	template<typename T>
	using Scope = std::unique_ptr<T>;

	/**
	 * @brief Creates a unique reference counted smart pointer.
	 * @tparam T The type of the object to reference.
	 * @param args The arguments to pass to the constructor of the object.
	 * @return A unique reference counted smart pointer to the new object.
	 */
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}