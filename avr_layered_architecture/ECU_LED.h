/*
 * ECU_LED.h
 *
 * Created: 9/3/2016 12:14:07 PM
 *  Author: Master
 */ 


#ifndef ECU_LED_H_
#define ECU_LED_H_

#include "ECU_LED_Config.h"
#include "MCAL_GPIO.h"

void LED_Init(void);

void LED_SetData(uint8_t LedId,LED_DataType LedData);

#endif /* ECU_LED_H_ */