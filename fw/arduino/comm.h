/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include "circular_buffer.h"


volatile struct cb_circular_buffer RX_BUFFER;
volatile struct cb_circular_buffer TX_BUFFER;


void comm_init(void);
