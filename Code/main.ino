#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <StreamUtils.h>
String sensorReadings;
String serverName = "http://citadelcollege.zportal.nl/api/v3/users/~me";

void setup() {
    Serial.begin(115200);
    WiFiManager wm;
    bool res;
    res = wm.autoConnect("RoosterBuddy AP"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }

}

void loop() {
  WiFiClientSecure client;  // or WiFiClientSecure for HTTPS
  HTTPClient http;

// Ask HTTPClient to collect the Transfer-Encoding header
// (by default, it discards all headers)
  const char* keys[] = {"Transfer-Encoding"};
  http.collectHeaders(keys, 1);

// Send request
  http.begin(client, "https://citadelcollege.zportal.nl/api/v3/users/~me");
  http.addHeader("access_token", "eeru2jpkkqpegl93s7uq9t37dg");
  http.GET();

// Get the raw and the decoded stream
  Stream& rawStream = http.getStream();
  ChunkDecodingStream decodedStream(http.getStream());

// Choose the right stream depending on the Transfer-Encoding header
  Stream& response =
    http.header("Transfer-Encoding") == "chunked" ? decodedStream : rawStream;

// Parse response
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, response);

// Read values
  Serial.println(doc.as<long>());

// Disconnect
  http.end();
  
}
