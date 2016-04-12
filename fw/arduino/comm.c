/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <avr/io.h>
#include <avr/sfr_defs.h>

#define BAUD 115200
#include <util/setbaud.h>

#include "circular_buffer.h"
#include "comm.h"


void comm_init(void)
{
	CB_INIT(RX_BUFFER);
	CB_INIT(TX_BUFFER);

	/* Baud rate */
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	/* Double-speed? */
#ifdef USE_2X
	UCSR0A |= _BV(U2X0);
#else
	UCSR0A &= ~(_BV(U2X0));
#endif /* USE_2X */

	UCSR0C |= (_BV(UCSZ01) | _BV(UCSZ00));

	/* Enable RX & TX */
	UCSR0B |= (_BV(RXEN0) | _BV(TXEN0));

	/* Flush RX */
	while (bit_is_set(UCSR0A, RXC0))
		{
			uint8_t c = UDR0;
		}

	/* Enable RX & TX interrupt */
	UCSR0B |= (_BV(RXCIE0) | _BV(TXCIE0));
}
