/*
 * ECU_LED.c
 *
 * Created: 9/3/2016 12:15:02 PM
 *  Author: Master
 */ 
 #include "ECU_LED.h"
 

 extern const LED_ConfigType LED_ConfigParam[LED_NUMBER];
 void LED_Init(void)
 {
	 uint8_t LoopIndex;
	 GPIO_Init_Param_t LedParam;
	 LedParam.IsPulledUp = 0;
	 LedParam.Direction = 0xff;
	 for(LoopIndex = 0; LoopIndex < LED_NUMBER; LoopIndex ++)
	 {
		 /*Collect  initialization parameters for each LED*/
		 LedParam.Mask = 1 << LED_ConfigParam[LoopIndex].PinNum;
		// LedParam.Direction = 1 << LED_ConfigParam[LoopIndex].PinNum;
		 LedParam.Port_Name = LED_ConfigParam[LoopIndex].PortName;
		 GPIO_Init(&LedParam);
		 LED_SetData(LoopIndex,OFF);
		 
	 }
 }

 void LED_SetData(uint8_t LedId,LED_DataType LedData)
 {
	 
	 GPIO_Write_Param_t LedParam;
	 LedParam.Port_Name = LED_ConfigParam[LedId].PortName;
	 LedParam.Mask = 1 << LED_ConfigParam[LedId].PinNum;

	 switch(LedData)
	 {
		case  OFF:
		if ( LED_ConfigParam[LedId].ConnectionType == ACTIVE_HIGH)
		{
		 LedParam.Data = 0;
		}
		else
		{
		 LedParam.Data = 1 << LED_ConfigParam[LedId].PinNum;
		}

		break;

		case ON:
		if ( LED_ConfigParam[LedId].ConnectionType == ACTIVE_HIGH)
		{
			LedParam.Data = 1 << LED_ConfigParam[LedId].PinNum;
		}
		else
		{
			LedParam.Data = 0;
		}
		break;

		default:
		// MISRA rule
		break;

	 }


	 GPIO_Write(&LedParam);

	 

 }