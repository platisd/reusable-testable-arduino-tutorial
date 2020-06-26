#pragma once

#include "Car.h"
#include "RestServer.h"

namespace magic_car
{
class MagicCarController
{
public:
    MagicCarController(Car& car, RestServer& restServer);

    void registerDriveEndpoint();
    void registerGyroscopeEndpoint();
    void registerErrorHandler();
    void beginServer();
    void update();

private:
    Car& mCar;
    RestServer& mRestServer;
};
} // namespace magic_car