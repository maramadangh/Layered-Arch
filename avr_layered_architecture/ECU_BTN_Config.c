/*
 * ECU_BTN_Config.c
 *
 * Created: 9/4/2016 4:40:45 PM
 *  Author: Master
 */ 
 #include "ECU_BTN_Config.h"

 const BTN_ConfigType BTN_CongfigParam[BTN_NUMBER] =
 {
	 {
		 BTN_ACTIVE_HIGH,1,PT1
	 },
	 {
		 BTN_ACTIVE_LOW,2,PT1
	 },
	 {
		 BTN_ACTIVE_LOW,0,PT2
	 }
 };