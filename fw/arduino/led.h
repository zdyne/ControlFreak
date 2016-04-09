/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>

#include <avr/io.h>


/* Error LED */
#define LED_ERROR_DDR DDRD
#define LED_ERROR_PORT PORTD
#define LED_ERROR_PIN PD2

void led_error_init(void);

void led_error_blink(uint8_t n);

void led_error_on(void);

void led_error_off(void);
