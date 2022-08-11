#include <gtest/gtest.h>
#include <GreenLizard/Numeric.hpp>

using namespace GreenLizard;

TEST(Numerics, uint64_to_uint64)
{
	uint64_t from = std::numeric_limits<uint64_t>::max();
	auto to = Numeric::StrictIntCast<uint64_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, uint32_to_uint32)
{
	uint32_t from = std::numeric_limits<uint32_t>::max();
	auto to = Numeric::StrictIntCast<uint32_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, uint16_to_uint16)
{
	uint16_t from = std::numeric_limits<uint16_t>::max();
	auto to = Numeric::StrictIntCast<uint16_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, uint8_to_uint8)
{
	uint8_t from = std::numeric_limits<uint8_t>::max();
	auto to = Numeric::StrictIntCast<uint8_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, int64_to_int64)
{
	int64_t from = std::numeric_limits<int64_t>::max();
	auto to = Numeric::StrictIntCast<int64_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, int32_to_int32)
{
	int32_t from = std::numeric_limits<int32_t>::max();
	auto to = Numeric::StrictIntCast<int32_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, int16_to_int16)
{
	int16_t from = std::numeric_limits<int16_t>::max();
	auto to = Numeric::StrictIntCast<int16_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, int8_to_int8)
{
	int8_t from = std::numeric_limits<int8_t>::max();
	auto to = Numeric::StrictIntCast<int8_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, float_to_float)
{
	float from = std::numeric_limits<float>::max();
	auto to = Numeric::StrictFloatCast<float>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, double_to_double)
{
	double from = std::numeric_limits<double>::max();
	auto to = Numeric::StrictFloatCast<double>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, long_double_to_long_double)
{
	long double from = std::numeric_limits<long double>::max();
	auto to = Numeric::StrictFloatCast<long double>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, float_to_double)
{
	float from = std::numeric_limits<float>::max();
	auto to = Numeric::StrictFloatCast<double>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, double_to_long_double)
{
	double from = std::numeric_limits<double>::max();
	auto to = Numeric::StrictFloatCast<long double>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, double_to_int64)
{
	double from = std::numeric_limits<double>::max();
	auto to = Numeric::FitCast<int64_t>(from);
	// TODO: test throws exception
	// ASSERT_EQ(to, from);
}