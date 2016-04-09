/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>

#include "circular_buffer.h"

enum command_id
	{
		COMMAND_ID_DBG_SET_BLOWER_POWER
	};


uint8_t command_ready(void);

void command_process(void);

