/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once


#include <stdint.h>


void temperature_init(void);

void temperature_start(void);

void temperature_read(void);

uint16_t temperature_dbg_raw_adc(void);
