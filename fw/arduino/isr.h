/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>

#include <avr/interrupt.h>
#include <util/delay.h>

#include "circular_buffer.h"
#include "comm.h"


ISR(USART_RX_vect)
{
	cb_put(&rx_buffer, UDR0);
}

