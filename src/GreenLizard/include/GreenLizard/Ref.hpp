#pragma once

#include <memory>

namespace GreenLizard
{
	// token from https://github.com/TheCherno/Hazel/blob/49da3c1e08245feb5b978269119f50b0873dc9d1/Hazel/src/Hazel/Core/Base.h#L38
	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}