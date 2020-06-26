#pragma once

namespace magic_car
{
struct Car
{
    virtual ~Car() = default;

    virtual void setSpeed(float speed) = 0;
    virtual void setAngle(int angle)   = 0;
    virtual void update()              = 0;
    virtual int getHeading()           = 0;
};
} // namespace magic_car
