#pragma once

#include "Car.h"
#include "gmock/gmock.h"

namespace magic_car
{
class MockCar : public Car
{
public:
    MOCK_METHOD(void, setSpeed, (float speed), (override));
    MOCK_METHOD(void, setAngle, (int angle), (override));
    MOCK_METHOD(void, update, (), (override));
    MOCK_METHOD(int, getHeading, (), (override));
};
} // namespace magic_car