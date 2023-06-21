/*
 * Ultra_Sonic.c
 *
 * Created: 5/1/2023 3:17:32 PM
 *  Author: Mohamed
 */ 
#define F_CPU 8000000ul
#include <util/delay.h>
#include "std_macro.h"
#include "DIO.h"
#include "timer.h";
#include <avr/io.h>
void US_init()
{
		//ultra sonic INTI
		DIO_vsetPINDir('a',3,1);
		DIO_vsetPINDir('D',6,0);
}
int US_read_distance(char direction)
{
	if(direction=='F')
	{
		timer1_wave_fastPWM(1.89);
	}			
	else if (direction=='R')
	{
		timer1_wave_fastPWM(0.95);
	}
	else
	{
		timer1_wave_fastPWM(2.7);	
	}
	int distance = Read_F_distance();
	return distance;
}

int Read_F_distance(){
	int a,b,high;
	int distance;
	
	DIO_write_pin('a',3,1);
	_delay_us(50);
	DIO_write_pin('a',3,0);
	
	int count =0;
	while((PIND & (1<<6)) >> 6 == 0);
	//calculate the ECHO time
	while((PIND& (1<<6)) >>6 == 1){
		// Converting The Counts To Microseconds Variable
		_delay_us(1);
		count++;
	}
	distance = count/9;					// Distance Equation.
	// FORWOARD
	//timer1_wave_fastPWM(1.89);
	return distance;
}