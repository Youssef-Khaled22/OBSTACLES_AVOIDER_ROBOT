/*
 * timer.h
 *
 * Created: 4/14/2023 5:13:46 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_


void timer_CTC_init_interrupt(void);
void timer1_wave_fastPWM(double value);
void timer0_wave_fastPWM(char dutyCycle);

#endif /* TIMER_H_ */