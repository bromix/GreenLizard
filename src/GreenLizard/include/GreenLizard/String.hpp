#pragma once

#include <string>
#include <optional>

#include "Environment.hpp"

namespace GreenLizard
{
	class String final
	{
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
		String(const wchar_t* string);

		/**
		 * @brief Move constructor.
		 */
		String(std::basic_string<Environment::CharacterType>&& string);

		/**
		 * @brief Move constructor.
		 * @param other
		 */
		String(String&& other) noexcept;

		/**
		 * @brief Move operator.
		 * @param other
		 */
		String& operator=(String&& other) noexcept;

		/**
		 * @brief Check if the string is null.
		 * @return True if the string is null, false otherwise.
		 */
		bool IsNull() const;

		/**
		 * @brief Prepend a string to this string.
		 * @param other The string to prepend.
		 * @return The resulting string.
		 */
		String Prepend(const String& other) const;

		/**
		 * @brief Determine if the string is empty.
		 * @return True if the string is empty, false otherwise.
		 */
		bool IsEmpty();

		/**
		 * @brief Determine if the given string is equal to this string.
		 * @return True if the strings are equal, false otherwise.
		 */
		bool operator==(const String& other) const;

		/**
		 * @brief Determine if the given string is not equal to this string.
		 * @return True if the strings are not equal, false otherwise.
		 */
		bool operator!=(const String& other) const;

		// FIXME: I don't like this.
		const Environment::CharacterType* c_str() const;

	 private:
		std::optional<std::basic_string<Environment::CharacterType>> stringBuffer;
	};

	String operator+(const String& lhs, const String& rhs);
}