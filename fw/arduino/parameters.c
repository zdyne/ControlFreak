/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <avr/eeprom.h>

#include "parameters.h"
#include "temperature.h"


static struct parameters EEMEM saved_params = { 10 };


void parameters_load(void)
{
	struct parameters current_params;

	eeprom_busy_wait();
	eeprom_read_block((void *)&current_params,
					  (const void *)&saved_params,
					  sizeof(struct parameters));

	temperature_set_params(current_params.n_samples_avg);
}


struct parameters parameters_read(void)
{
	struct parameters current_params;

	eeprom_busy_wait();
	eeprom_read_block((void *)&current_params,
					  (const void *)&saved_params,
					  sizeof(struct parameters));

	return current_params;
}


void parameters_update(struct parameters *new_params)
{
	eeprom_busy_wait();
	eeprom_update_block((const void *)new_params,
						(void *)&saved_params,
						sizeof(struct parameters));
}
