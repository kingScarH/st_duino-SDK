/*
 * @FILE     :    button_interrupt_blink.c
 * @AUTHOR   :    Sandeep ray
 * @BRIEF    :    Blink LED on button press using external interrupt (GPIO EXTI)
 */

#include <st_duino.h>
#include <stdbool.h>

// Store current LED state
volatile bool led_state = false;

// Interrupt Service Routine for button press
void onButtonPress() {
    led_state = !led_state;
    digitalWrite(BUILTIN_LED, led_state ? HIGH : LOW);
}

void setup() {
    pinMode(BUILTIN_LED, OUTPUT);
    pinMode(BUILTIN_SWITCH, INPUT_PULLUP);  // Assuming button is active-low

    // Attach interrupt to the button pin on FALLING edge
    attachInterrupt(13, onButtonPress, FALLING);

    Serial.begin(9600);
    Serial.println("Ready. Press the button to toggle LED.");
}

void loop() {
    // Do nothing, everything is handled by interrupt
    delay(1000);  // debug purpose k liye loop ko jivit rakhna awashyak hai
}
