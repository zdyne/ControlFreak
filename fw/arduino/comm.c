/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#define BAUD 9600
#include <util/setbaud.h>

#include "circular_buffer.h"
#include "comm.h"


void comm_init(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

#ifdef USE_2X
	
#else

#endif /* USE_2X */

	cb_init(&rx_buffer);
	cb_init(&tx_buffer);
}
