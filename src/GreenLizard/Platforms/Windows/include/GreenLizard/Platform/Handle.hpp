#pragma once

#include "Windows.hpp"

namespace GreenLizard::Platform
{
	class Handle
	{
	 public:
		/**
		 * @brief Default constructor.
		 */
		Handle();

		/**
		 * @brief Destructor.
		 * @remarks If the handle is owned by the handle, it will be closed.
		 */
		~Handle();

		/**
		 * @brief Constructor.
		 * @param handle The handle.
		 * @param ownsHandle Whether the handle is owned by the handle or not.
		 */
		Handle(::HANDLE handle, bool ownsHandle = true);

		/**
		 * @brief Determine whether the handle is valid.
		 * @return true if the handle is valid, false otherwise.
		 */
		[[nodiscard]] bool IsInvalid() const;

		/**
		 * @brief Determine whether the handle is null.
		 * @return true if the handle is null, false otherwise.
		 */
		[[nodiscard]] bool IsNull() const;

		/**
		 * @brief Determine whether the handle is null or invalid.
		 * @return true if the handle is null or invalid, false otherwise.
		 */
		[[nodiscard]] bool IsNullOrInvalid() const;

		/**
		 * @brief Determine whether the handle owns the handle.
		 * @return true if the handle owns the handle, false otherwise.
		 */
		[[nodiscard]] bool OwnsHandle() const;

		/**
		 * @brief SafeCast to ::HANDLE.
		 */
		operator ::HANDLE() const;

	 private:
		::HANDLE handle = nullptr;
		bool ownsHandle = true;
	};
}