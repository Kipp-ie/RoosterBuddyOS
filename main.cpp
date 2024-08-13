#include "pico/stdlib.h"
#include "cpp_wifidriver.cpp"
#include <cstdio> // Include the C standard IO functions

int main() {
    stdio_init_all(); // Initialize standard IO

    while (true) {
        printf("Starting up Rooster-Buddy");
// Splash image on the e-ink display.
        printf("Connecting to wifi....");
        WiFi wireless; //Initialization is done automatically
        wireless.init(); //Returns true if the initialization succeeded (should be used in an if)
    
        wireless.connect(SSID, PASSWORD, AUTH, WIFI_TIMEOUT);
        printf("WiFi: Local IP - %s\n", wireless.localIP().toString().c_str());
    
        wireless.disconnect(true); //Blocking disconnect
   
        wireless.deinit();
// When it does connect try connecting to the magister servers. If not display text that it can't connect to wifi/magister servers
// Fetch information from the magister servers.
// Display the next 2 lessons on the screen

// If the button is pressed refresh the lessons
// If the button is being held for 5 seconds create a wifi network for configuration.
    }
}