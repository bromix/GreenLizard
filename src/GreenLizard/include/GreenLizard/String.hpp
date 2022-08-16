#pragma once

#include <string>
#include <optional>

namespace GreenLizard
{
	class String final
	{
	 public:
#if defined(_WIN32) || defined(_WINDOWS)
		using CharacterType = wchar_t;
#else
		using CharacterType = char;
#endif

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
		 * @brief Constructor from char*
		 * @param string The string to copy.
		 * @param length The length of the string to copy.
		 */
		String(const char* string, size_t length);

		/**
		 * @brief Constructor from wchar_t*.
		 */
		String(const wchar_t* string);

		/**
		 * @brief Constructor from wchar_t*.
		 * @param string The string to copy.
		 * @param length The length of the string to copy.
		 */
		String(const wchar_t* string, size_t length);

		/**
		 * @brief Move constructor.
		 */
		String(std::basic_string<String::CharacterType>&& string);

		/**
		 * @brief Copy constructor.
		 * @param string The string to copy.
		 */
		String(const String& other);

		/**
		 * @brief Copy operator.
		 * @param other The string to copy.
		 */
		String& operator=(const String& other);

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
		[[nodiscard]] bool IsNull() const;

		/**
		 * @brief Prepend a string to this string.
		 * @param other The string to prepend.
		 * @return The resulting string.
		 */
		[[nodiscard]] String Prepend(const String& other) const;

		/**
		 * @brief Determine if the string is empty.
		 * @return True if the string is empty, false otherwise.
		 */
		[[nodiscard]] bool IsEmpty() const;

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

		/**
		 * @brief Returns a pointer to underlying string.
		 * @return A pointer to underlying string.
		 */
		[[nodiscard]] const String::CharacterType* c_str() const;
	 private:
		std::optional<std::basic_string<String::CharacterType>> stringBuffer;
	};

	String operator+(const String& lhs, const String& rhs);
}