/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <stdint.h>

#include <util/delay.h>

#include "circular_buffer.h"
#include "command.h"
#include "led.h"
#include "comm.h"
#include "blower.h"
#include "temperature.h"


static void cmd_send_response(void);

static void cmd_set_blower_power(void);
static void cmd_get_blower_rpm(void);
static void cmd_get_temperature_raw_adc(void);


typedef void (*cmd_fp_t)(void);

static cmd_fp_t CMDS[] =
	{
		cmd_set_blower_power,
		cmd_get_blower_rpm,
		cmd_get_temperature_raw_adc
	};


/**
 * Command format
 * 0x55, [CMD_ID], [N_BYTES], [DATA 0], ..., [DATA N-1], [CHECKSUM]
 */
uint8_t command_ready(void)
{
	uint8_t command_size = 0;

	if (CB_LEN(RX_BUFFER) < 3)
		{
			return 0;
		}

	command_size = CB_PEEK_AT(RX_BUFFER, 2) + 4;

	if (CB_LEN(RX_BUFFER) < command_size)
		{
			return 0;
		}

	return 1;
}


void command_process(void)
{
	uint8_t esc;

	esc = CB_POP(RX_BUFFER);

	if (esc != 0x55)
		{
			led_error_on();
		}

	CMDS[CB_POP(RX_BUFFER)]();
}


static void cmd_set_blower_power(void)
{
	uint8_t n = CB_POP(RX_BUFFER);

	if (n != 1)
		{
			led_error_on();
		}

	n = CB_POP(RX_BUFFER);

	blower_set_power(n);

	n = CB_POP(RX_BUFFER);

	/* Create response */
	CB_PUSH(TX_BUFFER, COMMAND_ID_DBG_SET_BLOWER_POWER);
	CB_PUSH(TX_BUFFER, 0x01);
	CB_PUSH(TX_BUFFER, 0x00);
	CB_PUSH(TX_BUFFER, 0xFE);

	cmd_send_response();
}


static void cmd_get_blower_rpm(void)
{
	uint16_t rpm = 0;

	uint8_t n = CB_POP(RX_BUFFER);


	if (n != 0)
		{
			led_error_on();
		}

	n = CB_POP(RX_BUFFER);

	CB_PUSH(TX_BUFFER, COMMAND_ID_DBG_GET_BLOWER_RPM);
	CB_PUSH(TX_BUFFER, 0x02);
	rpm = blower_get_tach();
	CB_PUSH(TX_BUFFER, (uint8_t)(rpm & 0xFF));
	CB_PUSH(TX_BUFFER, (uint8_t)((rpm >> 8) & 0xFF));
	CB_PUSH(TX_BUFFER, 0xFD);

	cmd_send_response();
}


static void cmd_get_temperature_raw_adc(void)
{
	uint16_t raw = 0;

	uint8_t n = CB_POP(RX_BUFFER);

	if (n != 0)
		{
			led_error_on();
		}

	n = CB_POP(RX_BUFFER);

	CB_PUSH(TX_BUFFER, COMMAND_ID_DBG_GET_TEMPERATURE_RAW_ADC);
	CB_PUSH(TX_BUFFER, 0x02);
	raw = temperature_dbg_raw_adc();
	CB_PUSH(TX_BUFFER, (uint8_t)(raw & 0xFF));
	CB_PUSH(TX_BUFFER, (uint8_t)((raw >> 8) & 0xFF));
	CB_PUSH(TX_BUFFER, 0xDE);

	cmd_send_response();
}


static void cmd_send_response(void)
{
	UDR0 = 0x55;
}
