#pragma once

#include <functional>
#include <vector>

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <string>
#endif

namespace magic_car
{

#if defined(ARDUINO)
using String = String;
#else
using String = std::string;
#endif

struct RestServer
{
    virtual ~RestServer() = default;

    virtual void begin()                                                    = 0;
    virtual void on(const char* endpoint, std::function<void()> callback)   = 0;
    virtual void onNotFound(std::function<void()> callback)                 = 0;
    virtual int args()                                                      = 0;
    virtual String argName(int index)                            = 0;
    virtual int argToInt(int index)                                         = 0;
    virtual void send(int errorCode, const char* type, const char* payload) = 0;
    virtual void handleClient()                                             = 0;
};
} // namespace magic_car