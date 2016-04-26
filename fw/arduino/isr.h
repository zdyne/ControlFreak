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
#include "blower.h"
#include "timer.h"
#include "led.h"


volatile uint8_t blower_update_tach = 0;
volatile uint8_t temperature_read_start = 0;
volatile uint8_t temperature_read_ready = 0;


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


ISR(USART_TX_vect)
{
	if (CB_LEN(TX_BUFFER) > 0)
		{
			UDR0 = CB_POP(TX_BUFFER);
		}
}


ISR(PCINT2_vect)
{
	if (BLOWER_TACH_PIN > 0)
		{
			blower_tach_pulses++;
		}
}


ISR(TIMER1_OVF_vect)
{
	timer_load_tcnt();

	blower_update_tach = 1;
	temperature_read_start = 1;
}


ISR(ADC_vect)
{
	temperature_read_ready = 1;
}
