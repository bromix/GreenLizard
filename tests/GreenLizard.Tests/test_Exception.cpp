#include <gtest/gtest.h>
#include <GreenLizard/Exception.hpp>

using namespace GreenLizard;

TEST(Exception, Throw)
{
	try {
		throw Exception("This is an exception");
	}
	catch (const Exception& e) {
		ASSERT_EQ(e.Message(), "This is an exception");
		ASSERT_EQ(std::string(e.what()), "This is an exception");
	}
}