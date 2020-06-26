#pragma once

namespace magic_car
{
enum class PinDirection
{
    kInput,
    kOutput
};

struct PinController
{
    virtual ~PinController() = default;

    virtual void setPinDirection(int pin, PinDirection pinDirection) = 0;
    virtual void setPin(int pin)                                     = 0;
    virtual void clearPin(int pin)                                   = 0;
};
} // namespace magic_car
