#include <gtest/gtest.h>
#include <GreenLizard/Environment.hpp>

using namespace GreenLizard;

TEST(Environment, MachineName)
{
	auto machineName = Environment::MachineName();
	ASSERT_FALSE(machineName.IsEmpty());
}

TEST(Enviroment, UserName)
{
	auto userName = Environment::UserName();
	ASSERT_FALSE(userName.IsEmpty());
}