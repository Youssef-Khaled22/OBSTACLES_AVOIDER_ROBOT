/*
 * Motor.c
 *
 * Created: 5/1/2023 4:35:23 PM
 *  Author: Mohamed
 */ 
#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "std_macro.h"
#include "DIO.h"
#include "timer.h"
void M_init()
{
	DIO_vsetPINDir('B',4,1);
	DIO_vsetPINDir('B',5,1);
	DIO_vsetPINDir('B',6,1);
	DIO_vsetPINDir('B',7,1);
}
void Mstop()
{
	DIO_write_pin('B',4,0);
	DIO_write_pin('B',5,0);
	
	DIO_write_pin('B',6,0);
	DIO_write_pin('B',7,0);
	
	
}
void Mforward()
{
	Mspeed(8);
	DIO_write_pin('B',4,0);
	DIO_write_pin('B',5,1);
	
	DIO_write_pin('B',6,0);
	DIO_write_pin('B',7,1);
}
void Mback() 
{
	Mspeed(8);
	DIO_write_pin('B',4,1);       //right wheel
	DIO_write_pin('B',5,0);
	
	DIO_write_pin('B',6,1);
	DIO_write_pin('B',7,0);
}
void Mleft()
{

	Mspeed(15);
	DIO_write_pin('B',4,0);      //right wheel 
	DIO_write_pin('B',5,1);
	
	DIO_write_pin('B',6,1);      //left wheel   
	DIO_write_pin('B',7,0);
	
	_delay_ms(375);
	Mstop();
	
}
void Mright()
{
	Mspeed(15);
	DIO_write_pin('B',4,1);
	DIO_write_pin('B',5,0);
	
	DIO_write_pin('B',6,0);
	DIO_write_pin('B',7,1);
	
	_delay_ms(375);
	Mstop();
}
void Mspeed(char dutyCycle)
{
	timer0_wave_fastPWM(dutyCycle);
}