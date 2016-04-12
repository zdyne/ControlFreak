/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <avr/sfr_defs.h>
#include <avr/io.h>

#include "timer.h"


volatile uint16_t tcnt = 0;


void timer_init(void)
{
	/* Set to normal mode */
	TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
	TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));

	/* Prescalar to 1024 */
	TCCR1B |= (_BV(CS12) | _BV(CS10));

	/* Overflow interrupt */
	TIMSK1 |= _BV(TOIE1);

	/* Compute TCNT for 1 second interrupt:
	 * 16 MHz / 1024 = 15.625 kHz
	 * 65536 - 15625 = 49911 tcnt
	 */
	tcnt = 49911;
	timer_load_tcnt();
}


void timer_load_tcnt(void)
{
	TCNT1 = tcnt;
}
