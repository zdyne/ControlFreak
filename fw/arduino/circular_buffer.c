/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include "circular_buffer.h"


void cb_init(struct cb_circular_buffer *cb)
{
	cb->head = 0;
	cb->tail = 0;
}


void cb_put(struct cb_circular_buffer *cb, uint8_t b)
{
	uint8_t next = (cb->head + 1)  % CB_MAX_LEN;
	
	cb->buffer[cb->head] = b;
	cb->head = next;
}


enum cb_status cb_get(struct cb_circular_buffer *cb, uint8_t *b)
{
	if (cb->head == cb->tail) {
		return CB_STATUS_EMPTY;
	}

	*b = cb->buffer[cb->tail];
	cb->tail = (cb->tail + 1) % CB_MAX_LEN;
}
