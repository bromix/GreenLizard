#include <gtest/gtest.h>

#include <GreenLizard/IO/Pipes/NamedPipeClientStream.hpp>

using namespace GreenLizard::IO::Pipes;

void test(GreenLizard::IO::IStream& stream)
{
    stream.Write("Hello World!", 0, 12);
}

TEST(Pipes_NamedPipes, Ctor)
{
    NamedPipeClientStream stream(L"test");
    stream.Connect();
    test(stream);
    ASSERT_TRUE(true);
}