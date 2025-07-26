/*
 * @FILE     :    simple blink and print (stduino SDK)
 * @AUTHOR   :     Sandeep Ray
 *
 *******************************************************************************************/
#include <st_duino.h>

void setup(){
	pinMode(BUILTIN_LED, OUTPUT);
	Serial.begin(9600);
}

void loop(){
	digitalWrite(BUILTIN_LED, HIGH);
	Serial.println("");// jo marzi apki likh dijiye andar 
	delay(1000);
	digitalWrite(BUILTIN_LED, LOW);
	Serial.println(" ");
	delay(1000);

}
