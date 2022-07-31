#include <gtest/gtest.h>

#include <GreenLizard/IO/Pipes/NamedPipeClientStream.hpp>

using namespace GreenLizard::IO::Pipes;

TEST(Pipes_NamedPipes, Ctor)
{
    NamedPipeClientStream stream("test");
    stream.Connect();
    ASSERT_TRUE(true);
}