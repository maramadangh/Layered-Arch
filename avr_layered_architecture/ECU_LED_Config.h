/*
 * ECU_LED_Config.h
 *
 * Created: 9/3/2016 12:13:36 PM
 *  Author: Master
 */ 


#ifndef ECU_LED_CONFIG_H_
#define ECU_LED_CONFIG_H_

#include "MCAL_GPIO.h"

#define LED_NUMBER (3)

typedef enum {ACTIVE_LOW=0,ACTIVE_HIGH} LED_ConnectionType;

typedef struct
{
	LED_ConnectionType ConnectionType;
	unsigned char PinNum;
	GPIO_Port_Name_t PortName;
}LED_ConfigType;

typedef enum {OFF=0,ON} LED_DataType;


#endif /* ECU_LED_CONFIG_H_ */