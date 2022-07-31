#pragma once

#include <memory>

#include <GreenLizard/String.hpp>

namespace GreenLizard::IO::Pipes
{
    class NamedPipeClientStream final
    {
    public:
        explicit NamedPipeClientStream(const String &pipeName);

        /**
         * @brief Connects to a waiting server with an infinite time-out value.
         */
        void Connect();

        /**
         * @brief Connects to a waiting server with a specified time-out value.
         * 
         * @param timeOut 
         */
        void Connect(const uint32_t timeOut);

    private:
        class Impl;
        std::shared_ptr<Impl> impl;
    };
}