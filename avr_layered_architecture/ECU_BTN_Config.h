/*
 * ECU_BTN_Config.h
 *
 * Created: 9/4/2016 4:40:23 PM
 *  Author: Master
 */ 


#ifndef ECU_BTN_CONFIG_H_
#define ECU_BTN_CONFIG_H_
#include "MCAL_GPIO.h"
#define BTN_NUMBER 3

typedef enum {BTN_ACTIVE_LOW =0, BTN_ACTIVE_HIGH} BTN_ConnectionType;

typedef struct
{
	BTN_ConnectionType ConnetionType;
	unsigned char PinNumber;
	GPIO_Port_Name_t PortName;
}BTN_ConfigType;

typedef enum {BTN_OFF =0, BTN_ON, BTN_JUST_PRESSED, BTN_JUST_RELEASED} BTN_StateType;




#endif /* ECU_BTN_CONFIG_H_ */