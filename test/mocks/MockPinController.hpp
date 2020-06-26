#pragma once

#include "PinController.h"

namespace magic_car
{
class MockPinController : public PinController
{
public:
    MOCK_METHOD2(setPinDirection, void(int pin, PinDirection pinDirection));
    MOCK_METHOD1(setPin, void(int pin));
    MOCK_METHOD1(clearPin, void(int pin));
};
} // namespace magic_car
