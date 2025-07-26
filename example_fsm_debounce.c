/*
 * @FILE     :    button_interrupt_blink.c
 * @AUTHOR   :    Sandeep Ray A.K.A KingScarH 
 * @BRIEF    :    fsm switch
 *
 *
 *
 */
#include <st_duino.h>
#include "button_fsm.h"

button_t myButton;

void setup(){
	Serial.begin(9600);
	pinMode(BUILTIN_SWITCH, INPUT_PULLUP);
	button_init(&myButton, BUILTIN_SWITCH);
}
void loop(){
	button_update(&myButton);

	if(button_is_pressed(&myButton))Serial.println("BUTTON PRESSED!");
}
