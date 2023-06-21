/*
 * timer.c
 *
 * Created: 4/14/2023 5:13:15 PM
 *  Author: Mohamed
 */ 
#include "std_macro.h"
#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=80;
	/* select timer clock  1024 */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	SET_BIT(TIMSK,OCIE0);
}
void timer1_wave_fastPWM(double value)
{
	TCCR1A=0X00;
	TCCR1B=0X00;
	/*set oc1a AS output pin*/
	SET_BIT(DDRD,5);
	/* select fast Pwm mode */
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	OCR1A=value*1000;
	ICR1=19999;
	/* select prescaling    /8    */
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

	/*clear OC1A on  compare,set on top*/
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	// 20 MS  BUT TO SWITCH
	_delay_ms(600);
	//CLR_BIT(DDRD,5);	
}
void timer0_wave_fastPWM(char dutyCycle) //(0-->100) %
{
	DIO_vsetPINDir('B',3,1);
	
	//fast pwm
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	// duty=(OCR0/256)X100
	OCR0=(dutyCycle*256)/100;
	//PRESCALLER   /64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	// Clear OC0 on compare match, set OC0 at TOP
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
}
