#pragma once

#include "Car.h"
#include <car/heading/HeadingCar.hpp>

namespace magic_car
{
class MagicCar : public Car
{
public:
    MagicCar(HeadingCar& car);

    void setSpeed(float speed) override;
    void setAngle(int angle) override;
    void update() override;
    int getHeading() override;

private:
    HeadingCar& mCar;
};
} // namespace magic_car