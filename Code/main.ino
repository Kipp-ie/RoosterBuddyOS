#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ESP8266HTTPClient.h>
String sensorReadings;
String serverName = "https://citadelcollege.zportal.nl/api/v3/users/~me&access_token=eeru2jpkkqpegl93s7uq9t37dg";

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
  if(WiFi.status()== WL_CONNECTED){ //Check WiFi connection status
    HTTPClient http;
    String serverpath = serverName;
    http.begin(serverpath.c_str());
    int httpResponseCode = http.GET();
    Serial.print(httpResponseCode);

    if (httpResponseCode>0) {
      Serial.print("HTTP Response Code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Error Code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
}}
