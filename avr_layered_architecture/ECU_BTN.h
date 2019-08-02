/*
 * ECU_BTN.h
 *
 * Created: 9/4/2016 4:41:00 PM
 *  Author: Master
 */ 


#ifndef ECU_BTN_H_
#define ECU_BTN_H_

#include "ECU_BTN_Config.h"


void BTN_Init(void);
BTN_StateType BTN_GetState(uint8_t BtnId);

#endif /* ECU_BTN_H_ */