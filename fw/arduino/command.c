/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <stdint.h>

#include <util/delay.h>

#include "circular_buffer.h"
#include "command.h"
#include "led.h"
#include "comm.h"


/**
 * Command format
 * 0x55, [CMD_ID], [N_BYTES], [DATA 0], ..., [DATA N-1], [CHECKSUM]
 */
uint8_t command_ready(void)
{
	uint8_t command_size = 0;

	if (CB_LEN(RX_BUFFER) < 3)
		{
			return 0;
		}

	command_size = CB_PEEK_AT(RX_BUFFER, 2) + 4;

	if (CB_LEN(RX_BUFFER) < command_size)
		{
			return 0;
		}

	return 1;
}


void command_process(void)
{
	uint8_t esc;

	esc = CB_POP(RX_BUFFER);

	if (esc != 0x55)
		{
			led_error_on();
		}

	esc = CB_POP(RX_BUFFER);
	esc = CB_POP(RX_BUFFER);
	esc = CB_POP(RX_BUFFER);
}
