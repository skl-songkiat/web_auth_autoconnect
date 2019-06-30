#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <FS.h>

ESP8266WebServer server(80);

String header;

void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("Connected.");

  if (!SPIFFS.begin())
  {
    // Serious problem
    Serial.println("SPIFFS Mount failed");
  } else {
    Serial.println("SPIFFS Mount succesfull");
  }

  // Makes index page and images available
  server.serveStatic("/", SPIFFS, "/index.html");

  // Start Web Server
  server.begin();
  Serial.println ( "HTTP server started" );
}

void loop() {
  server.handleClient();
}
