#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <HttpClient.h>

String serverName = "https://citadelcollege.zportal.nl/api";

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
  HttpClient http;
  String serverPath = serverName + "/v3/users/~me&access_token=kk8j2smb9nv8h19isieds9nku1";

  // Your Domain name with URL path or IP address with path
  http.begin(serverPath.c_str());

  // If your need Node-RED/server authentication, insert user and password below
  //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");

  // Send HTTP GET request
  int httpResponseCode = http.GET();
  if (httpResponseCode>0) {
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  String payload = http.getString();
  Serial.println(payload);
  }
  else {
  Serial.print("Error code: ");
  Serial.println(httpResponseCode);
  }
  // put your main code here, to run repeatedly:   
}
