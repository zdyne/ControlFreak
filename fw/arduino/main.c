/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <util/delay.h>

#include "comm.h"
#include "command.h"
#include "isr.h"
#include "led.h"


int main(int argc, char *argv[])
{
	/* Configure I/O */
	led_error_init();

	/* Configure timers */

	/* Configure serial port */
	comm_init();

	/* Load PID parameters */

	/* Enable interrupts */
	sei();

	while (1)
		{
			if (command_ready())
				{
					command_process();
				}

			_delay_ms(2000.0);
		}
}
