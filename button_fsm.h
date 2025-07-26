/*
*  @FILE         : button_fsm.h
*  @AUTHOR       : Sandeep Ray (callme KingscarH)
*
*/



#ifndef BUTTON_FSM_H
#define BUTTON_FSM_H

#include <stdint.h>
#include <stdbool.h>
#include "pinmap.h"   // Required for pin_t definition , ye sdk core me ek separate file me defined hai 

// -----------------------------------------------------------------------------
// ENUMS
// -----------------------------------------------------------------------------

/**
 * @brief Enumeration of button states for FSM
 */
typedef enum {
    BTN_IDLE = 0,      ///< Button is idle (not pressed)  __ADARSH AWASTHA__
    BTN_DEBOUNCE,      ///< Debouncing in progress
    BTN_PRESSED        ///< Button is pressed and stable
} button_state_t;

// -----------------------------------------------------------------------------
// STRUCTS
// -----------------------------------------------------------------------------

/**
 * @brief Button object structure to manage FSM state
 */
typedef struct {
    pin_t pin;                    ///< GPIO pin associated with button
    button_state_t state;        ///< Current FSM state
    uint32_t last_debounce_time; ///< Timestamp for debounce handling
    bool pressed_flag;           ///< One-shot flag to indicate button press
} button_t;

// -----------------------------------------------------------------------------
// FUNCTION PROTOTYPES
// -----------------------------------------------------------------------------

/**
 * @brief Initialize button structure and configure GPIO pin
 *
 * @param btn Pointer to button object
 * @param pin GPIO pin to which button is connected
 */
void button_init(button_t* btn, pin_t pin);

/**
 * @brief Update the button state machine;  periodically hi call hoga ye 
 *
 * @param btn Pointer to button object
 */
void button_update(button_t* btn);

/**
 * @brief Check if button was pressed (one-shot flag)
 *
 * @param btn Pointer to button object
 * @return true  If button was pressed since last check
 * @return false If button was not pressed
 */
bool button_is_pressed(button_t* btn);

#endif // BUTTON_FSM_H
