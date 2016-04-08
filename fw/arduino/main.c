/*
 * Copyright 2016, Patrick J. Franz
 *
 */


#include "comm.h"
#include "isr.h"


int main(int argc, char *argv[])
{
	/* Configure I/O */
	/* PB0 -> Arduino Pin 8 */
	DDRB |= _BV(PB0);
	PORTB &= ~(_BV(PB0));

	/* Configure timers */

	/* Configure serial port */
	comm_init();

	/* Load PID parameters */

	/* Enable interrupts */
	sei();

	while (1)
		{

		}
}
