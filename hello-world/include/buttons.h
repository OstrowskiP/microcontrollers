/*
 * buttons.h
 *
 *  Created on: 07.01.2017
 *      Author: Piotrek
 */

#ifndef INCLUDE_BUTTONS_H_
#define INCLUDE_BUTTONS_H_

// nazwa rejestrow dla klawiszy
#define BUTTONS_DDR		DDRB
#define BUTTONS_PORT	PORTB
#define BUTTONS_PIN		PINB

// czy uzywac funkcji buttonAction(pinNumber, action)
#define USE_BUTTON_ACTION_PINNO_ACTION

// czy uzywac funkcji uint8_t buttonAction(pinNumber)
#define USE_BUTTON_ACTION_PINNO

// inicjalizacja klawiszy
void buttonsInit();

// reakcja na nacisniecie klawisza pinNumber
void buttonActionCallback(uint8_t pinNumber, void (*action)(void));

// reakcja na nacisniecie klawisza pinNumber
uint8_t buttonAction(uint8_t pinNumber);

#endif /* INCLUDE_BUTTONS_H_ */
