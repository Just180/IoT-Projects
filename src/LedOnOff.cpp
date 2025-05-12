#include <WiFi.h>
#include <WebServer.h>

// AP credentials
const char* ssid = "ESP32_AP";
const char* password = "12345678";

// Web server on port 80
WebServer server(80);

// GPIO for LED (optional)
const int ledPin = 2;

void ledON() {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED is ON");
}

void ledOFF() {
  digitalWrite(ledPin, LOW);
  Serial.println("LED is OFF");
}

void handleRoot() {
  String html = "<!DOCTYPE html>\
  <html>\
  <head>\
    <title>ESP32 Web Server</title>\
    <style>\
      body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; background-color: #f4f4f4; }\
      h2 { color: #333; }\
      .button {\
        display: inline-block;\
        padding: 15px 30px;\
        margin: 20px;\
        font-size: 20px;\
        cursor: pointer;\
        text-align: center;\
        text-decoration: none;\
        outline: none;\
        color: #fff;\
        background-color: #4CAF50;\
        border: none;\
        border-radius: 10px;\
        box-shadow: 0 5px #999;\
      }\
      .button:hover { background-color: #45a049; }\
      .button:active {\
        background-color: #45a049;\
        box-shadow: 0 2px #666;\
        transform: translateY(4px);\
      }\
      .off-button { background-color: #f44336; }\
      .off-button:hover { background-color: #da190b; }\
    </style>\
  </head>\
  <body>\
    <h2> ESP32 Server is Working!</h2>\
    <form action=\"/on\" method=\"get\">\
      <button class=\"button\" type=\"submit\">Turn ON</button>\
    </form>\
    <form action=\"/off\" method=\"get\">\
      <button class=\"button off-button\" type=\"submit\">Turn OFF</button>\
    </form>\
  </body>\
  </html>";
  
  server.send(200, "text/html", html);
}

void handleOn() {
  ledON();
  server.sendHeader("Location", "/");
  server.send(303); // Redirect back to main page
}

void handleOff() {
  ledOFF();
  server.sendHeader("Location", "/");
  server.send(303);
}
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Start AP
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Setup routes
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
