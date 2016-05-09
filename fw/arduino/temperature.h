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

void temperature_set_params(uint8_t n_samples_avg);
