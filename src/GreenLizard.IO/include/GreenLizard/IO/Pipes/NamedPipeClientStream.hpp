#pragma once

#include <memory>

#include <GreenLizard/String.hpp>
#include <GreenLizard/IO/IStream.hpp>

namespace GreenLizard::IO::Pipes
{
    class NamedPipeClientStream final: public virtual IStream
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

        void Write(const void *buffer, const uint32_t offset, const uint32_t length);
    private:
        class Impl;
        std::shared_ptr<Impl> impl;
    };
}