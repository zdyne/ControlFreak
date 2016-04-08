/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>

#include "circular_buffer.h"

enum command_id
	{
		COMMAND_ID_DBG_SET_FAN
	};


uint8_t command_ready(struct cb_circular_buffer *buf);

void command_process(struct cb_circular_buffer *buf);

