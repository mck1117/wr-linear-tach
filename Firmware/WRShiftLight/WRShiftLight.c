/*
* WRShiftLight.c
*
* Created: 10/8/2014 21:53:05
*  Author: Matthew
*/


#include <avr/io.h>
#include <avr/common.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "WRShiftConfig.h"



#define SET(on, port, pin)		\
{								\
	if(on)						\
	{							\
		port &= ~_BV(pin);		\
	}							\
	else						\
	{							\
		port |= _BV(pin);		\
	}							\
}

#define GET(port, pin)			\
(port & _BV(pin))

void setLeds(uint8_t vals)
{
	SET(vals & 0x01, LED_0_PORT, LED_0_PIN);
	vals = vals >> 1;
	SET(vals & 0x01, LED_1_PORT, LED_1_PIN);
	vals = vals >> 1;
	SET(vals & 0x01, LED_2_PORT, LED_2_PIN);
	vals = vals >> 1;
	SET(vals & 0x01, LED_3_PORT, LED_3_PIN);
	vals = vals >> 1;
	SET(vals & 0x01, LED_4_PORT, LED_4_PIN);
	vals = vals >> 1;
	SET(vals & 0x01, LED_5_PORT, LED_5_PIN);
	vals = vals >> 1;
	SET(vals & 0x01, LED_6_PORT, LED_6_PIN);
	vals = vals >> 1;
	SET(vals & 0x01, LED_7_PORT, LED_7_PIN);
}

uint32_t rpm_per_pulse_per_sec = 0;

inline void setupTimer()
{
	// Set up timer 1 at fcpu/8
	// For a 6cyl, this means the minimum measureable is ~350 RPM.
	// At 6k RPM, we get ~1.7 RPM accuracy
	TCCR1B |= _BV(CS11);
}

inline void setupInterrupt()
{
	// Set up external interrupt INT0 so that we hit our vector below.
	
	// Trigger INT0 on rising edge
	MCUCR |= _BV(ISC00) || _BV(ISC01);
	// Enable INT0
	GIMSK |= _BV(INT0);
}

void setupLeds()
{
	// Set all to output
	LED_0_DDR |= _BV(LED_0_PIN);
	LED_1_DDR |= _BV(LED_1_PIN);
	LED_2_DDR |= _BV(LED_2_PIN);
	LED_3_DDR |= _BV(LED_3_PIN);
	LED_4_DDR |= _BV(LED_4_PIN);
	LED_5_DDR |= _BV(LED_5_PIN);
	LED_6_DDR |= _BV(LED_6_PIN);
	LED_7_DDR |= _BV(LED_7_PIN);
}

int main(void)
{
	cli();
	// Disable the watchdog
	wdt_disable();
	
	// Setup LEDS
	setupLeds();
	
	// Two second blink
	setLeds(0xFF);
	_delay_ms(2000);
	setLeds(0);
	
	setupTimer();
	
	setupInterrupt();

	// Enable interrupts
	sei();
	
	// Halt
	while(1);
}

ISR(INT0_vect)
{
	if(PIND & _BV(PIND2))
	{
		cli();
		// Reset the watchdog so we don't reboot
		//WDR();
		
		// Grab the timer count
		uint16_t count = TCNT1;
		TCNT1 = 0;
		// Calculate engine RPM
		uint16_t rpm =  RPM_PER_PULSE_PER_SEC / count;
		
		// Set the LEDs
		uint8_t leds = 0;
		
		if(rpm > LED_0_POINT)
		{
			leds |= _BV(0);
		}
		
		if(rpm > LED_1_POINT)
		{
			leds |= _BV(1);
		}
		
		if(rpm > LED_2_POINT)
		{
			leds |= _BV(2);
		}
		
		if(rpm > LED_3_POINT)
		{
			leds |= _BV(3);
		}
		
		if(rpm > LED_4_POINT)
		{
			leds |= _BV(4);
		}
		
		if(rpm > LED_5_POINT)
		{
			leds |= _BV(5);
		}
		
		if(rpm > LED_6_POINT)
		{
			leds |= _BV(6);
		}
		
		if(rpm > LED_7_POINT)
		{
			leds |= _BV(7);
		}
		
		setLeds(leds);
	}
}

