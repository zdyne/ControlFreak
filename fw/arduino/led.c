/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <stdint.h>

#include <avr/io.h>

#include <util/delay.h>

#include "led.h"


void led_error_init(void)
{
	LED_ERROR_DDR |= _BV(LED_ERROR_PIN);
}


void led_error_blink(uint8_t n)
{
	uint8_t i;

	for (i = 0; i < n; i++)
		{
			led_error_on();
			_delay_ms(500.0);
			led_error_off();
			_delay_ms(500.0);			
		}
}


void led_error_on(void)
{
	LED_ERROR_PORT |= _BV(LED_ERROR_PIN);
}


void led_error_off(void)
{
	LED_ERROR_PORT &= ~(_BV(LED_ERROR_PIN));
}

