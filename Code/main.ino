#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <esp8266httpclient.h>

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
  if(WiFi.status()== WL_CONNECTED){ //Check WiFi connection status
  
    HTTPClient http; //Declare an object of class HTTPClient
    WiFiClient espClient;
    http.begin(espClient, "https://citadelcollege.zportal.nl/api/v3/users/~me&access_token=kk8j2smb9nv8h19isieds9nku1"); //Specify request destination
    int httpCode = http.GET(); //Send the request
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString(); //Get the request response payload
      Serial.println(payload); //Print the response payload
    }
    http.end(); //Close connection
  } else {
    Serial.println("Error in WiFi connection");  
  }
  delay(30000); //Send a request every 30 seconds
}
