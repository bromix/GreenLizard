#pragma once

#include "Windows.hpp"

namespace GreenLizard::Platform {
    class Handle {
    public:
        Handle(const Handle &other) = delete;

        Handle(Handle &&other) = delete;

        Handle &operator=(const Handle &other) = delete;

        /**
         * @brief Default constructor.
         */
        Handle() = default;

        /**
         * @brief Destructor.
         */
        ~Handle();

        /**
         * @brief Constructor with a handle.
         *
         * @param handle
         */
        Handle(const ::HANDLE &handle);


        /**
         * @brief Assignment operator.
         * @param other
         * @return this
         */
        Handle &operator=(const ::HANDLE &other);

        /**
         * @brief Move operator.
         * @param other
         * @return this
         */
        Handle &operator=(Handle &&other);

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

        bool IsNullOrInvalid() const;

        /**
         * @brief Cast to ::HANDLE.
         */
        operator ::HANDLE() const;

    private:
        ::HANDLE handle = nullptr;
    };
}