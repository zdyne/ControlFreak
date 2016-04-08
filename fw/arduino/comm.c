/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <avr/io.h>

#define BAUD 9600
#include <util/setbaud.h>

#include "circular_buffer.h"
#include "comm.h"


void comm_init(void)
{
	/* Baud rate */
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	/* Double-speed? */
#ifdef USE_2X
	UCSR0A |= _BV(U2X0);
#else
	UCSR0A &= ~(_BV(U2X0));
#endif /* USE_2X */

	UCSR0B |= (_BV(RXCIE0) | _BV(RXEN0));
	UCSR0C |= (_BV(UCSZ01) | _BV(UCSZ00));

	cb_init(&rx_buffer);
	cb_init(&tx_buffer);
}
