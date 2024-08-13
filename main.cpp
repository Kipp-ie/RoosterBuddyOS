#include "pico/stdlib.h"
#include <cstdio> // Include the C standard IO functions

int main() {
    stdio_init_all(); // Initialize standard IO

    while (true) {
        printf("Starting up Rooster-Buddy");
// Splash image on the e-ink display.
        printf("Connecting to wifi....");
// Should connect to wifi now
// When it does connect try connecting to the magister servers. If not display text that it can't connect to wifi/magister servers
// Fetch information from the magister servers.
// Display the next 2 lessons on the screen

// If the button is pressed refresh the lessons
// If the button is being held for 5 seconds create a wifi network for configuration.
    }
}