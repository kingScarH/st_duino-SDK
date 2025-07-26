/*
 * @FILE     : button_fsm.c
 * @AUTHOR   : Sandeep Ray (aka KINGSCARH)
 * @BRIEF    : Finite State Machine for Button Input with Debouncing
 *
 * This module implements a non-blocking button press detection system
 * using a simple FSM. It is designed for embedded systems and works 
 * with the st_duino SDK. The input is assumed to be active LOW.
 *
 * MIT License
 * Copyright (c) 2025 Sandeep Ray
 */

#include "button_fsm.h"
#include <st_duino.h>  // st_duino core APIs

//----------------------------------------------------------------------------------
// Macros & Constants
//----------------------------------------------------------------------------------
#define DEBOUNCE_DELAY 50  // milliseconds

//----------------------------------------------------------------------------------
// Public API Implementations
//----------------------------------------------------------------------------------

void button_init(button_t* btn, pin_t pin) {
    btn->pin = pin;
    btn->state = BTN_IDLE;
    btn->last_debounce_time = millis();
    btn->pressed_flag = false;

    pinMode(pin, INPUT_PULLUP);  // Active LOW assumed
}

void button_update(button_t* btn) {
    bool raw = (digitalRead(btn->pin) == 0);  // Active LOW logic

    switch (btn->state) {
        case BTN_IDLE:
            if (raw) {
                btn->state = BTN_DEBOUNCE;
                btn->last_debounce_time = millis();
            }
            break;

        case BTN_DEBOUNCE:
            if ((millis() - btn->last_debounce_time) > DEBOUNCE_DELAY) {
                if (raw) {
                    btn->state = BTN_PRESSED;
                    btn->pressed_flag = true;
                } else {
                    btn->state = BTN_IDLE;
                }
            }
            break;

        case BTN_PRESSED:
            if (!raw) {
                btn->state = BTN_IDLE;
            }
            break;
    }
}

bool button_is_pressed(button_t* btn) {
    if (btn->pressed_flag) {
        btn->pressed_flag = false;
        return true;
    }
    return false;
}
