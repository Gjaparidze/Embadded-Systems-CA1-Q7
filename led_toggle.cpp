#include "mbed.h"

// Create DigitalOut objects for two LEDs
DigitalOut led1(LED1);
DigitalOut led2(LED2);

// Create Ticker objects for timing
Ticker led1_ticker;
Ticker led2_ticker;

// Function to toggle LED1 every 2 seconds
void toggle_led1() {
    led1 = !led1;  // Toggle the state of LED1
}

// Function to toggle LED2 every 5 seconds
void toggle_led2() {
    led2 = !led2;  // Toggle the state of LED2
}

int main() {
    // Attach the toggle functions to the respective Ticker objects
    led1_ticker.attach(&toggle_led1, 2.0);  // Toggle every 2 seconds
    led2_ticker.attach(&toggle_led2, 5.0);  // Toggle every 5 seconds

    // Infinite loop to keep the program running
    while (true) {
        // No action needed in the main loop as the tickers handle the LED toggling
        ThisThread::sleep_for(1000ms);  // Sleep for 1 second to prevent high CPU usage
    }
}
