/*
 * LED.h
 *
 * Created: 1/31/2023 5:52:01 PM
 *  Author: Sarah
 */ 


#ifndef LED_H_
#define LED_H_

void LED_vInit(unsigned char portname,unsigned char pinnumber);
void LED_vTurnOn(unsigned char portname,unsigned char pinnumber);
void LED_vTurnOff(unsigned char portname,unsigned char pinnumber);
void LED_vToggle(unsigned char portname,unsigned char pinnumber);
unsigned char LED_cRead_status(unsigned char portname,unsigned char pinnumber);




#endif /* LED_H_ */