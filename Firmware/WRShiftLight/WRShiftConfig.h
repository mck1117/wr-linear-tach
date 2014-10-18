/*
 * WRShiftConfig.h
 *
 * Created: 10/9/2014 08:21:32
 *  Author: Matthew
 */ 


#ifndef WRSHIFTCONFIG_H_
#define WRSHIFTCONFIG_H_

// ******************************
//     LED Activation Points
// ******************************

#define LED_0_POINT 500
#define LED_1_POINT 1000
#define LED_2_POINT 2000
#define LED_3_POINT 3000
#define LED_4_POINT 4000
#define LED_5_POINT 5000
#define LED_6_POINT 6000
#define LED_7_POINT 6500

// ******************************
//           LED Pins
// ******************************

#define LED_0_DDR	DDRB
#define LED_0_PORT	PORTB
#define LED_0_PIN	PINB4
#define LED_1_DDR	DDRB
#define LED_1_PORT	PORTB
#define LED_1_PIN	PINB3
#define LED_2_DDR	DDRB
#define LED_2_PORT	PORTB
#define LED_2_PIN	PINB2
#define LED_3_DDR	DDRB
#define LED_3_PORT	PORTB
#define LED_3_PIN	PINB1
#define LED_4_DDR	DDRB
#define LED_4_PORT	PORTB
#define LED_4_PIN	PINB0
#define LED_5_DDR	DDRD
#define LED_5_PORT	PORTD
#define LED_5_PIN	PIND6
#define LED_6_DDR	DDRD
#define LED_6_PORT	PORTD
#define LED_6_PIN	PIND4
#define LED_7_DDR	DDRD
#define LED_7_PORT	PORTD
#define LED_7_PIN	PIND5


// ******************************
//      Cylinder Select Pins
// ******************************
#define SEL_4_CYL_DDR DDRA
#define SEL_4_CYL_PINS PINA
#define SEL_4_CYL_PORT PORTA
#define SEL_4_CYL_PIN PINA1

#define SEL_6_CYL_DDR DDRD
#define SEL_6_CYL_PINS PIND
#define SEL_6_CYL_PORT PORTD
#define SEL_6_CYL_PIN PIND1

#define SEL_8_CYL_DDR DDRD
#define SEL_8_CYL_PINS PIND
#define SEL_8_CYL_PORT PORTD
#define SEL_8_CYL_PIN PIND0

// ******************************
//      Engine & Timer Config
// ******************************

#define SECONDS_PER_MINUTE 60
#define COUNTER_FREQ 1000000



#define WDR() {__asm__ __volatile__ ("wdr");}



#endif /* WRSHIFTCONFIG_H_ */