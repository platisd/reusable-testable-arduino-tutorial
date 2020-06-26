#include <ESPmDNS.h>
#include <Smartcar.h>
#include <WiFi.h>

#include "Esp32RestServer.h"
#include "MagicCar.h"
#include "MagicCarController.h"
#include "ArduinoPinController.h"

const auto ssid     = "yourSSID";
const auto password = "yourWifiPassword";

WebServer server(80);

ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);

GY50 gyroscope(arduinoRuntime, 11);

HeadingCar car(control, gyroscope);

magic_car::MagicCar magicCar{car};
magic_car::Esp32RestServer esp32RestServer{server};
magic_car::ArduinoPinController pinController;

magic_car::MagicCarController magicCarController{
    magicCar, esp32RestServer, pinController};

void setup(void)
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    if (MDNS.begin("smartcar"))
    {
        MDNS.addService("http", "tcp", 80);
        Serial.println("MDNS responder started");
    }

    magicCarController.registerDriveEndpoint();

    magicCarController.registerGyroscopeEndpoint();

    magicCarController.registerErrorHandler();

    magicCarController.beginServer();

    Serial.println("HTTP server started");
}

void loop(void)
{
    magicCarController.update();
}
