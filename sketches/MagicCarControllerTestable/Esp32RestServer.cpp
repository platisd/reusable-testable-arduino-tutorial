#include "Esp32RestServer.h"

namespace magic_car
{
Esp32RestServer::Esp32RestServer(WebServer& webServer)
    : mWebServer{webServer}
{
}

void Esp32RestServer::begin()
{
    mWebServer.begin();
}

void Esp32RestServer::on(const char* endpoint, std::function<void()> callback)
{
    mWebServer.on(endpoint, callback);
}

void Esp32RestServer::onNotFound(std::function<void()> callback)
{
    mWebServer.onNotFound(callback);
}

int Esp32RestServer::args()
{
    return mWebServer.args();
}

String Esp32RestServer::argName(int index)
{
    String name = mWebServer.argName(index);
    return name;
}

int Esp32RestServer::argToInt(int index)
{
    return mWebServer.arg(index).toInt();
}

void Esp32RestServer::send(int errorCode, const char* type, const char* payload)
{
    mWebServer.send(errorCode, type, payload);
}

void Esp32RestServer::handleClient()
{
    mWebServer.handleClient();
}
} // namespace magic_car
