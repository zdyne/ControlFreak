/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include "circular_buffer.h"
#include "commh."


void comm_init(void)
{
	cb_init(&rx_buffer);
	cb_init(&tx_buffer);
}
