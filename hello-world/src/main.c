/*
 * main.c
 *
 *  Created on: 07.01.2017
 *      Author: OstrowskiP
 */

#include <avr/io.h>
#include "../include/buttons.h"



void f1() {
	PORTB ^= 1 << 1;
}

int main() {
	buttonsInit();

	// Input PIN is turned down by default
	DDRB |= (1 << 1); // Set a bit in PIN to mark as OUTPUT

	while (1) {
		buttonActionCallback(0, f1);
	}
	return 0;
}

