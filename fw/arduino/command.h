/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>

#include "circular_buffer.h"

enum command_id
	{
		COMMAND_ID_DBG_SET_BLOWER_POWER,
		COMMAND_ID_DBG_GET_BLOWER_RPM,
		COMMAND_ID_DBG_GET_TEMPERATURE_RAW_ADC,
		COMMAND_ID_GET_PARAMETERS,
		COMMAND_ID_SET_PARAMETERS
	};


uint8_t command_ready(void);

void command_process(void);

