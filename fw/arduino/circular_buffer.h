/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>


#define CB_MAX_LEN 64

struct cb_circular_buffer
{
	uint8_t buffer[CB_MAX_LEN];
	uint8_t head;
	uint8_t tail;
};


#define CB_INIT(b) b.head = b.tail = 0

#define CB_LEN(b) ((typeof(b.head))((b.head) - (b.tail)))

#define CB_PUSH(b, c) (b.buffer)[b.head++ & (CB_MAX_LEN - 1)] = (c)

#define CB_POP(b) (b.buffer)[b.tail++ & (CB_MAX_LEN - 1)]

#define CB_PEEK_AT(b, idx) (b.buffer)[(b.tail + idx) & (CB_MAX_LEN - 1)]


enum cb_status
	{
		CB_STATUS_OK,
		CB_STATUS_EMPTY
	};

void cb_init(struct cb_circular_buffer *cb);

void cb_put(struct cb_circular_buffer *cb, uint8_t b);

enum cb_status cb_get(struct cb_circular_buffer *cb, uint8_t *b);

uint8_t cb_count(struct cb_circular_buffer *cb);

uint8_t cb_peek_at(struct cb_circular_buffer *cb, uint8_t idx);
