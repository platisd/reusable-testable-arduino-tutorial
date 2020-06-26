#pragma once

#include "Car.h"
#include "PinController.h"
#include "RestServer.h"

namespace magic_car
{
class MagicCarController
{
public:
    MagicCarController(Car& car,
                       RestServer& restServer,
                       PinController& pinController);

    void registerDriveEndpoint();
    void registerGyroscopeEndpoint();
    void registerErrorHandler();
    void beginServer();
    void update();

private:
    Car& mCar;
    RestServer& mRestServer;
    PinController& mPinController;
};
} // namespace magic_car
