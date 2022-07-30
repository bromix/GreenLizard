#include <gtest/gtest.h>

#include <GreenLizard/IO/Pipes/NamedPipeClientStream.hpp>

using namespace GreenLizard::IO::Pipes;

TEST(NamedPipes, Ctor)
{
    NamedPipeClientStream stream("test");
    ASSERT_TRUE(true);
}