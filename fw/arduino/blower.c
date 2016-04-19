/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <avr/sfr_defs.h>
#include <avr/io.h>

#include "blower.h"

#define BLOWER_RANGE_25KHZ 80

volatile uint8_t blower_tach_pulses = 0;

static uint8_t blower_raw_rps = 0;


void blower_init(void)
{
	/* Configure tachometer interrupt */
	PCMSK2 |= _BV(PCINT20);
	PCICR |= _BV(PCIE2);

	/* Tach is open-collector and needs pull-up resistor */
	DDRD &= ~(_BV(PD4));
	PORTD |= _BV(PD4);

	/* For Fast PWM, allows us to set the duty cycle via OCR2B and freq w/ OCR2A */
	TCCR2A |= (_BV(COM2B1) | _BV(COM2A1));

	/* Fast PWM */
	TCCR2A |= (_BV(WGM21) | _BV(WGM20));
	TCCR2B |= _BV(WGM22);

	/* Set prescalar to divide by 8 */
	TCCR2B |= _BV(CS21);

	OCR2A = BLOWER_RANGE_25KHZ;
	OCR2B = 0;

	DDRD |= _BV(PD3);
}


void blower_set_power(uint8_t p)
{
	float percent = (float)p / 100.0f;
	float power = percent * (float)BLOWER_RANGE_25KHZ;
	OCR2B = (uint8_t)power;
}


void blower_compute_tach(void)
{
	blower_raw_rps = blower_tach_pulses / 2;
	blower_tach_pulses = 0;
}


uint16_t blower_get_tach(void)
{
	return blower_raw_rps * 60;
}
