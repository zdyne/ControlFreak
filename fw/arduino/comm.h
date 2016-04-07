/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include "circular_buffer.h"


struct cb_circular_buffer rx_buffer;
struct cb_circular_buffer tx_buffer;


void comm_init(void);
