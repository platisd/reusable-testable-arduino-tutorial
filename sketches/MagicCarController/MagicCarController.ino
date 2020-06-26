#include <ESPmDNS.h>
#include <Smartcar.h>
#include <WebServer.h>
#include <WiFi.h>

const auto ssid      = "yourSSID";
const auto password  = "yourWifiPassword";
const auto lightsPin = 2;

WebServer server(80);

ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);

GY50 gyroscope(arduinoRuntime, 11);

HeadingCar car(control, gyroscope);

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

    pinMode(lightsPin, OUTPUT);

    server.on("/drive", []() {
        const auto arguments = server.args();

        for (auto i = 0; i < arguments; i++)
        {
            const auto command = server.argName(i);
            if (command == "speed")
            {
                const auto userSpeed = server.arg(i).toInt();
                car.setSpeed(userSpeed);
                digitalWrite(lightsPin, userSpeed == 0 ? HIGH : LOW);
            }
            else if (command == "angle")
            {
                car.setAngle(server.arg(i).toInt());
            }
        }
        server.send(200, "text/plain", "ok");
    });

    server.on("/gyro", []() {
        server.send(200, "text/plain", String(car.getHeading()));
    });

    server.onNotFound(
        []() { server.send(404, "text/plain", "Unknown command"); });

    server.begin();
    Serial.println("HTTP server started");
}

void loop(void)
{
    server.handleClient();
    car.update();
}
