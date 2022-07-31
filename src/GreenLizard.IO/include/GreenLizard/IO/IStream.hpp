#pragma once

namespace GreenLizard::IO
{
    class IStream
    {
    public:
        virtual ~IStream() = default;
        // virtual void Close() = 0;
        // virtual bool IsClosed() const = 0;
        // virtual void Flush() = 0;
        // virtual bool IsFlushed() const = 0;
        // virtual void Seek(const int64_t offset, const SeekOrigin origin) = 0;
        // virtual int64_t Position() const = 0;
        // virtual int64_t Length() const = 0;
        virtual void Write(const void *buffer, const uint32_t offset, const uint32_t length) = 0;
        //virtual void Read(void *buffer, const uint32_t offset, const uint32_t length) = 0;
    };
}