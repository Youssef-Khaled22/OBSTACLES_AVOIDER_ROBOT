/*
 * LED.c
 *
 * Created: 1/31/2023 5:51:49 PM
 *  Author: Sarah
 */ 

#include "DIO.h"
void LED_vInit(unsigned char portname,unsigned char pinnumber)
{
	DIO_vsetPINDir(portname,pinnumber,1);
}
void LED_vTurnOn(unsigned char portname,unsigned char pinnumber)
{
	DIO_write_pin(portname,pinnumber,1);
}
void LED_vTurnOff(unsigned char portname,unsigned char pinnumber)
{
	DIO_write_pin(portname,pinnumber,0);
}
void LED_vToggle(unsigned char portname,unsigned char pinnumber)
{
	DIO_toggle_pin(portname,pinnumber);
}
unsigned char LED_cRead_status(unsigned char portname,unsigned char pinnumber)
{
	DIO_u8read(portname,pinnumber);
}