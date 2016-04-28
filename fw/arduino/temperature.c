/*
 * Copyright 2016, Patrick J. Franz
 *
 */

#include <avr/sfr_defs.h>
#include <avr/io.h>

#include "temperature.h"


static uint16_t temperature_raw_adc = 0;


void temperature_init(void)
{
	/* Disable power reduction */
	PRR &= ~(_BV(PRADC));

	/* Disable digital input */
	DIDR0 |= _BV(ADC0D);
	DDRC &= ~(_BV(PC0));
	PORTC &= ~(_BV(PC0));
	
	/* Set reference voltage */
	ADMUX |= _BV(REFS0);

	/* Set prescalar to 128: sampling freq -> 125 kHz */
	ADCSRA |= (_BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2));
	
	/* Enable ADC */
	ADCSRA |= _BV(ADEN);

	/* Enable interrupt */
	ADCSRA |= _BV(ADIE);
}


void temperature_start(void)
{
	/* Start ADC conversion */
	ADCSRA |= _BV(ADSC);
}


void temperature_read(void)
{
	temperature_raw_adc = (uint16_t)ADCL;
	temperature_raw_adc |= (uint16_t)ADCH << 8;	
}


uint16_t temperature_dbg_raw_adc(void)
{
	return temperature_raw_adc;
}
