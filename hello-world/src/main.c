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

	// PIN wej�cia w domy�le jest wy��czony
	DDRB |= (1 << 1); // Wprowadzamy PIN wyj�cia w stan wysoki

	while (1) {
		buttonActionCallback(0, f1);
	}
	return 0;
}

