/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>


struct parameters
{
	/* Temperature */
	uint8_t n_samples_avg;
};


void parameters_load(void);

struct parameters parameters_read(void);

void parameters_update(struct parameters *new_params);
