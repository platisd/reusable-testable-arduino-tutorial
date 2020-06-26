#include "Esp32RestServer.h"

namespace
{
MagicRestServer::MagicRestServer(WebServer& webServer)
    : mWebServer{webServer}
{
}

void MagicRestServer::begin()
{
    mWebServer.begin();
}

void MagicRestServer::on(const char* endpoint, std::function<void()> callback)
{
    mWebServer.on(endpoint, callback);
}

void MagicRestServer::onNotFound(std::function<void()> callback)
{
    mWebServer.onNotFound(callback);
}

int MagicRestServer::args()
{
    return mWebServer.args();
}

std::vector<char> MagicRestServer::argName(int index)
{
    const auto name = mWebServer.argName(index);
    std::vector<char> argumentName;
    for (auto c : name)
    {
        argumentName.emplace_back(c);
    }
    argumentName.emplace_back('\0'); // Null terminate the string

    return argumentName;
}

int MagicRestServer::argToInt(int index)
{
    return mWebServer.arg(index).toInt();
}

void MagicRestServer::send(int errorCode, const char* type, const char* payload)
{
    mWebServer.send(errorCode, type, payload);
}

void MagicRestServer::handleClient()
{
    mWebServer.handleClient();
}
} // namespace