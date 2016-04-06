/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include "circular_buffer.h"


volatile struct circular_buffer rx_buffer;
volatile struct circular_buffer tx_buffer;


void comm_init(void);
