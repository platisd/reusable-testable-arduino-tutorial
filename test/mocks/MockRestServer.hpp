#pragma once

#include "RestServer.h"
#include "gmock/gmock.h"

namespace magic_car
{
class MockRestServer : public RestServer
{
public:
    MOCK_METHOD(void, begin, (), (override));
    MOCK_METHOD(void,
                on,
                (const char* endpoint, std::function<void()> callback),
                (override));
    MOCK_METHOD(void, onNotFound, (std::function<void()> callback), (override));
    MOCK_METHOD(int, args, (), (override));
    MOCK_METHOD(std::vector<char>, argName, (int index), (override));
    MOCK_METHOD(int, argToInt, (int index), (override));
    MOCK_METHOD(void,
                send,
                (int errorCode, const char* type, const char* payload),
                (override));
    MOCK_METHOD(void, handleClient, (), (override));
};
} // namespace magic_car
