/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#pragma once

#include <stdint.h>


#define CB_MAX_LEN 64

struct cb_circular_buffer
{
	volatile uint8_t buffer[CB_MAX_LEN];
	volatile uint8_t head;
	volatile uint8_t tail;
};


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
