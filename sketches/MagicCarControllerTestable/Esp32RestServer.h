#pragma once

#include "RestServer.h"
#include <WebServer.h>

namespace magic_car
{
class Esp32RestServer : public RestServer
{
public:
    Esp32RestServer(WebServer& webServer);

    void begin() override;
    void on(const char* endpoint, std::function<void()> callback) override;
    void onNotFound(std::function<void()> callback) override;
    int args() override;
    std::vector<char> argName(int index) override;
    int argToInt(int index) override;
    void send(int errorCode, const char* type, const char* payload) override;
    void handleClient() override;

private:
    WebServer& mWebServer;
};
} // namespace magic_car