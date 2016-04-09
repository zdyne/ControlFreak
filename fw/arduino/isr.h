/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>

#include <avr/sfr_defs.h>
#include <avr/interrupt.h>

#include "circular_buffer.h"
#include "comm.h"


ISR(USART_RX_vect)
{
	if (bit_is_clear(UCSR0A, FE0) &&
		bit_is_clear(UCSR0A, DOR0) &&
		bit_is_clear(UCSR0A, UPE0))
		{
			CB_PUSH(RX_BUFFER, UDR0);
		}
	else
		{
			uint8_t b = UDR0;
		}
}

