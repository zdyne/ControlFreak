/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>


#define BLOWER_TACH_PIN PIND4


extern volatile uint8_t blower_tach_pulses;


void blower_init(void);

void blower_set_power(uint8_t p);

void blower_compute_tach(void);

uint16_t blower_get_tach(void);
