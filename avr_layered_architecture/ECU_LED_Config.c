/*
 * ECU_LED_Config.c
 *
 * Created: 9/3/2016 12:13:54 PM
 *  Author: Master
 */ 
 #include "ECU_LED_Config.h"

 const LED_ConfigType LED_ConfigParam[LED_NUMBER] =
 {
	 {
		 ACTIVE_HIGH, 6,PT2
	 }
	 ,
	 {
		 ACTIVE_HIGH, 4,PT3
	 }
	 ,
	 {
		 ACTIVE_HIGH, 0,PT4
	 }
 };