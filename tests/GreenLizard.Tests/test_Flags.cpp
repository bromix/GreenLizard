#include <gtest/gtest.h>
#include <GreenLizard/Flags.hpp>
using namespace GreenLizard;

enum class CarState : std::uint8_t
{
	engine_on = 0b00000001,
	lights_on = 0b00000010,
	wipers_on = 0b00000100,
};
using CarStates = Flags<CarState>;

TEST(Flags, Ctor_WithOne)
{
	CarStates car_states = CarState::engine_on;

	ASSERT_EQ(car_states, CarState::engine_on);
	ASSERT_NE(car_states, CarState::lights_on);
}

TEST(Flags, Ctor_WithTwo)
{
	CarStates car_states = {CarState::engine_on, CarState::lights_on};

	ASSERT_NE(car_states, CarState::lights_on);
}