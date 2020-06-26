#include "MagicCar.h"

namespace magic_car
{
MagicCar::MagicCar(HeadingCar& car)
    : mCar{car}
{
}

void MagicCar::setSpeed(float speed)
{
    mCar.setSpeed(speed);
}

void MagicCar::setAngle(int angle)
{
    mCar.setAngle(angle);
}

void MagicCar::update()
{
    mCar.update();
}

int MagicCar::getHeading()
{
    return mCar.getHeading();
}
} // namespace magic_car