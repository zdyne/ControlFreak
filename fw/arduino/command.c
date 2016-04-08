/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <stdint.h>

#include "circular_buffer.h"
#include "command.h"


/**
 * Command format
 * 0x55, [CMD_ID], [N_BYTES], [DATA 0], ..., [DATA N-1], [CHECKSUM], 
 */
uint8_t command_ready(struct cb_circular_buffer *buf)
{
	uint8_t command_size = 0;

	if (cb_count(buf) < 3)
		{
			return 0;
		}

	command_size = cb_peek_at(buf, 2) + 4;


	if (cb_count(buf) < command_size)
		{
			return 0;
		}

	return 1;
} 
