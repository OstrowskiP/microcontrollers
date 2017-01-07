/*
 * buttons.h
 *
 *  Created on: 07.01.2017
 *      Author: OstrowskiP
 */

#ifndef INCLUDE_BUTTONS_H_
#define INCLUDE_BUTTONS_H_

// Registers names used for buttons
#define BUTTONS_DDR		DDRB
#define BUTTONS_PORT	PORTB
#define BUTTONS_PIN		PINB

// Whether to use this function buttonAction(pinNumber, action)
#define USE_BUTTON_ACTION_PINNO_ACTION

// Whether to use this function buttonAction(pinNumber)
//#define USE_BUTTON_ACTION_PINNO

void buttonsInit();

// Button connected to PIN pinNumber with some action to be triggered
void buttonActionCallback(uint8_t pinNumber, void (*action)(void));

// Button connected to PIN pinNumber returning current button state
uint8_t buttonAction(uint8_t pinNumber);

#endif /* INCLUDE_BUTTONS_H_ */
