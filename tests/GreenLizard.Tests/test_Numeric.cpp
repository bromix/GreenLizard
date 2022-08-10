#include <gtest/gtest.h>
#include <GreenLizard/Numeric.hpp>

using namespace GreenLizard;

TEST(Numerics, uint64_to_uint64)
{
	uint64_t from = 0xFFFFFFFFFFFFFFFF;
	auto to = Numeric::SafeCast<uint64_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numerics, uint64_to_int64)
{
	uint64_t from = 0xFFFFFFFFFFFFFFFF;
	int64_t to2 = static_cast<int16_t>(from);
	auto to = Numeric::FitCast<int64_t>(from);
	ASSERT_EQ(to, from);

	from = -1;
	to = Numeric::FitCast<int64_t>(from);
	ASSERT_EQ(to, from);
}

TEST(Numeric, bool)
{
	bool from = true;
	auto to = Numeric::SafeCast<bool>(from);
	ASSERT_EQ(to, from);
}