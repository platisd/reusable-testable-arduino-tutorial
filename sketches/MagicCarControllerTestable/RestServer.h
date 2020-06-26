#pragma once

#include <functional>
#include <vector>

namespace magic_car
{
struct RestServer
{
    virtual ~RestServer() = default;

    virtual void begin()                                                    = 0;
    virtual void on(const char* endpoint, std::function<void()> callback)   = 0;
    virtual void onNotFound(std::function<void()> callback)                 = 0;
    virtual int args()                                                      = 0;
    virtual std::vector<char> argName(int index)                            = 0;
    virtual int argToInt(int index)                                         = 0;
    virtual void send(int errorCode, const char* type, const char* payload) = 0;
    virtual void handleClient()                                             = 0;
};
} // namespace magic_car