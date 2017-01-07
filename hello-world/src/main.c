/*
 * main.c
 *
 *  Created on: 07.01.2017
 *      Author: OstrowskiP
 */

#include <avr/io.h>
#include "../include/buttons.h"
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t gamma_correctionR[32] = { 0, 1, 1, 1, 2, 3, 5, 7, 10, 13, 17, 21, 26,
		32, 38, 45, 52, 60, 69, 78, 88, 99, 111, 124, 137, 151, 166, 182, 199,
		217, 235, 255 };

void f1() {
	PORTB ^= 1 << 1;
}

int main() {
	buttonsInit();

	TCCR2 |= (1 << WGM20) | (1 << WGM21); // Enabling fast PWM
	DDRB |= (1 << 3);
	TCCR2 |= (1 << CS21); // Timer 2(8bit) prescaler = 8 -> F_CPU/8 -> 8MHz/8 = 1Mhz
	TCCR2 |= (1 << COM21); // Output mode, clear on compare match, set at bottom -> 0 = 0%; 255 = 100%

	TCCR0 |= (1 << CS02) | (1 << CS00); // Timer 0(8bit) prescaler = 1024 -> ~7.8kHz
	TIMSK |= (1 << TOIE0); // Enable overflow interrupt

	// Input PIN is turned down by default
	DDRB |= (1 << 1); // Set a bit in PIN to mark as OUTPUT

	sei();
	while (1) {
		buttonActionCallback(0, f1);
	}
	return 0;
}

ISR(TIMER0_OVF_vect) {
	static volatile uint8_t gammaIndex, slope;
	if (!slope) {
		if (gammaIndex < 31)
			gammaIndex++;
		else
			slope = 1;
	}
	else {
		if (gammaIndex > 0)
			gammaIndex--;
		else
			slope = 0;
	}
//	TCNT0 = 254;
	OCR2 = gamma_correctionR[gammaIndex];
}
