/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <util/delay.h>

#include "comm.h"
#include "command.h"
#include "isr.h"
#include "led.h"
#include "timer.h"
#include "temperature.h"


static void process_temperatures(void);


int main(int argc, char *argv[])
{
	/* Configure time */
	timer_init();

	/* Configure I/O */
	led_error_init();
	blower_init();
	temperature_init();

	/* Configure serial port */
	comm_init();

	/* Load PID parameters */

	/* Enable interrupts */
	sei();

	while (1)
		{
			if (blower_update_tach)
				{
					blower_update_tach = 0;
					blower_compute_tach();
				}

			process_temperatures();


			if (command_ready())
				{
					command_process();
				}
		}
}


void process_temperatures(void)
{
	if (temperature_read_ready)
		{
			temperature_read_ready = 0;
			temperature_read();
		}

	if (temperature_read_start)
		{
			temperature_read_start = 0;
			temperature_start();
		}
}
