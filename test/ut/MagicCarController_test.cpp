#include "MagicCarController.h"
#include "MockCar.hpp"
#include "MockPinController.hpp"
#include "MockRestServer.hpp"
#include "gtest/gtest.h"

using namespace testing;

namespace
{
const auto kSuccess   = 200;
const auto kError     = 404;
const auto kLightsPin = 2;
const std::vector<char> kDummyName{'a', 'b', 'c', '\0'};
const std::vector<char> kSpeed{'s', 'p', 'e', 'e', 'd', '\0'};
const std::vector<char> kAngle{'a', 'n', 'g', 'l', 'e', '\0'};
} // namespace

namespace magic_car
{
struct MagicCarControllerTest : public Test
{
    MockCar mCar;
    MockRestServer mRestServer;
    MockPinController mPinController;
    MagicCarController mMagicCarController{mCar, mRestServer, mPinController};
};

struct DriveEndpointTest : public Test
{
    void SetUp() override
    {
        EXPECT_CALL(mRestServer, on(_, _)).WillOnce(SaveArg<1>(&mCallback));
        ON_CALL(mRestServer, argName(_)).WillByDefault(Return(kDummyName));

        mMagicCarController.registerDriveEndpoint();
    }

    MockCar mCar;
    MockRestServer mRestServer;
    MockPinController mPinController;
    MagicCarController mMagicCarController{mCar, mRestServer, mPinController};
    std::function<void()> mCallback;
};

TEST(MagicCarConstructorTest, constructor_WhenCalled_WillSetLightsPinDirection)
{
    MockCar car;
    MockRestServer restServer;
    MockPinController pinController;

    EXPECT_CALL(pinController,
                setPinDirection(kLightsPin, PinDirection::kOutput));
    MagicCarController mMagicCarController{car, restServer, pinController};
}

TEST_F(MagicCarControllerTest,
       registerDriveEndpoint_WhenCalled_WillRegisterEndpoint)
{
    EXPECT_CALL(mRestServer, on(StrEq("/drive"), _));

    mMagicCarController.registerDriveEndpoint();
}

TEST_F(MagicCarControllerTest,
       registerGyroscopeEndpoint_WhenCalled_WillRegisterEndpoint)
{
    EXPECT_CALL(mRestServer, on(StrEq("/gyro"), _));

    mMagicCarController.registerGyroscopeEndpoint();
}

TEST_F(MagicCarControllerTest, gyroscopeEndpoint_WhenCalled_WillSendHeading)
{
    std::function<void()> callback;
    EXPECT_CALL(mRestServer, on(_, _)).WillOnce(SaveArg<1>(&callback));
    mMagicCarController.registerGyroscopeEndpoint();

    const auto heading = 334;
    EXPECT_CALL(mCar, getHeading()).WillOnce(Return(heading));
    EXPECT_CALL(mRestServer,
                send(kSuccess, _, StrEq(std::to_string(heading).c_str())));

    callback();
}

TEST_F(MagicCarControllerTest,
       registerErrorHandler_WhenCalled_WillRegisterErrorHandler)
{
    EXPECT_CALL(mRestServer, onNotFound(_));

    mMagicCarController.registerErrorHandler();
}

TEST_F(MagicCarControllerTest, errorEndpoint_WhenCalled_WillSendError)
{
    std::function<void()> callback;
    EXPECT_CALL(mRestServer, onNotFound(_)).WillOnce(SaveArg<0>(&callback));
    mMagicCarController.registerErrorHandler();

    EXPECT_CALL(mRestServer, send(kError, _, _));
    callback();
}

TEST_F(MagicCarControllerTest, beginServer_WhenCalled_WillBeginServer)
{
    EXPECT_CALL(mRestServer, begin());

    mMagicCarController.beginServer();
}

TEST_F(MagicCarControllerTest, update_WhenCalled_WillUpdateServerAndCar)
{
    EXPECT_CALL(mRestServer, handleClient());
    EXPECT_CALL(mCar, update());

    mMagicCarController.update();
}

TEST_F(DriveEndpointTest, callback_WhenCalled_WillSendSuccess)
{
    EXPECT_CALL(mRestServer, send(kSuccess, _, _));
    mCallback();
}

TEST_F(DriveEndpointTest, callback_WhenNoArguments_WillNotFetchArguments)
{
    EXPECT_CALL(mRestServer, args()).WillOnce(Return(0));
    EXPECT_CALL(mRestServer, argName(_)).Times(0);

    mCallback();
}

TEST_F(DriveEndpointTest, callback_WhenArguments_WillGetAllArguments)
{
    const auto numberOfArguments = 8438;
    EXPECT_CALL(mRestServer, args()).WillOnce(Return(numberOfArguments));
    EXPECT_CALL(mRestServer, argName(_)).Times(numberOfArguments);

    mCallback();
}

TEST_F(DriveEndpointTest, callback_WhenSpeedAsArgument_WillSetSpeed)
{
    const auto speed = 512;
    EXPECT_CALL(mRestServer, args()).WillOnce(Return(1));
    EXPECT_CALL(mRestServer, argName(_)).WillOnce(Return(kSpeed));
    EXPECT_CALL(mRestServer, argToInt(_)).WillOnce(Return(speed));
    EXPECT_CALL(mCar, setSpeed(static_cast<float>(speed)));

    mCallback();
}

TEST_F(DriveEndpointTest, callback_WhenAngleAsArgument_WillSetAngle)
{
    const auto angle = 843;
    EXPECT_CALL(mRestServer, args()).WillOnce(Return(1));
    EXPECT_CALL(mRestServer, argName(_)).WillOnce(Return(kAngle));
    EXPECT_CALL(mRestServer, argToInt(_)).WillOnce(Return(angle));
    EXPECT_CALL(mCar, setAngle(angle));

    mCallback();
}

TEST_F(DriveEndpointTest,
       callback_WhenSpeedAndAngleAsArgument_WillSetSpeedAndAngle)
{
    const auto angle = -843;
    const auto speed = -512;
    EXPECT_CALL(mRestServer, args()).WillOnce(Return(2));
    EXPECT_CALL(mRestServer, argName(_))
        .WillOnce(Return(kAngle))
        .WillOnce(Return(kSpeed));
    EXPECT_CALL(mRestServer, argToInt(_))
        .WillOnce(Return(angle))
        .WillOnce(Return(speed));
    EXPECT_CALL(mCar, setAngle(angle));
    EXPECT_CALL(mCar, setSpeed(static_cast<float>(speed)));

    mCallback();
}
} // namespace magic_car
