/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>


extern volatile uint16_t tcnt;


void timer_init(void);

void timer_load_tcnt(void);
