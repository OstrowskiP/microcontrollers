/*
 * buttons.c
 *
 *  Created on: 07.01.2017
 *      Author: Piotrek
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../include/buttons.h"

#define KEY_THRESHOLD 50
#define KEY_PRESSED(x) (!(BUTTONS_PIN & (1 << x)))


void buttonsInit() {
	BUTTONS_DDR		= 0;
	BUTTONS_PORT	= 0xFF;
}


#ifdef USE_BUTTON_ACTION_PINNO_ACTION
void buttonActionCallback(uint8_t pinNumber, void (*action)(void)) {
	static uint8_t isPressed;
	if KEY_PRESSED(pinNumber) {
		if (!isPressed) {
			_delay_ms(KEY_THRESHOLD);
			if KEY_PRESSED(pinNumber) {
				action();
				isPressed = 1;
			}
		}
	} else
		isPressed = 0;
}
#endif

#ifdef USE_BUTTON_ACTION_PINNO
uint8_t buttonAction(uint8_t pinNumber) {
	static uint8_t isPressed;
	if KEY_PRESSED(pinNumber) {
		if (!isPressed) {
			_delay_ms(KEY_THRESHOLD);
			if KEY_PRESSED(pinNumber) {
				return 1;
				isPressed = 1;
			}
		}
	} else
		isPressed = 0;

	return 0;
}
#endif
