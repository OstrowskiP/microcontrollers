/*
 * main.c
 *
 *  Created on: 07.01.2017
 *      Author: Piotrek
 */

#include <avr/io.h>
#include "../include/buttons.h"



void f1() {
	PORTB ^= 1 << 1;
}

int main() {
	buttonsInit();

	// PIN wejœcia w domyœle jest wy³¹czony
	DDRB |= (1 << 1); // Wprowadzamy PIN wyjœcia w stan wysoki

	while (1) {
		buttonActionCallback(0, f1);
	}
	return 0;
}

