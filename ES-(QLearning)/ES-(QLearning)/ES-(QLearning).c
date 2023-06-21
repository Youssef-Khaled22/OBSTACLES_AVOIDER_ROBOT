/*
 * ES__QLearning_.c
 *
 * Created: 6/21/2023 7:26:07 AM
 *  Author: Mohamed
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "std_macro.h"
#include "DIO.h"
#include "Motor.h"
#include "Ultra_Sonic.h"
#include "timer.h"
#include "Qlearning.h"
#include "LED.h"

int main(void)
{
	US_init();
	M_init();
	
	LED_vInit('A',0);
	LED_vInit('A',1);
	
	LED_vTurnOn('A',1);
	train3();
	LED_vTurnOff('A',1);
	
	LED_vTurnOn('A',0);
	test2();
	LED_vTurnOff('A',0);
	// 	 infinite loop anyway
	
	_delay_ms(1000);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}