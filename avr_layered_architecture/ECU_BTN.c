/*
 * ECU_BTN.c
 *
 * Created: 9/4/2016 4:41:13 PM
 *  Author: Master
 */ 
 #include "ECU_BTN.h"


 extern const BTN_ConfigType BTN_CongfigParam[BTN_NUMBER];

 static BTN_StateType BtnState[BTN_NUMBER];

void BTN_Init(void)
{
	GPIO_Init_Param_t BtnParam;
	unsigned long int LoopIndex;
	BtnParam.Direction = 0x00;
	for(LoopIndex =0; LoopIndex < BTN_NUMBER; LoopIndex ++)
	{
		BtnParam.IsPulledUp = (!BTN_CongfigParam[LoopIndex].ConnetionType) << BTN_CongfigParam[LoopIndex].PinNumber;
		BtnParam.Mask = 1 << BTN_CongfigParam[LoopIndex].PinNumber;
		BtnParam.Port_Name = BTN_CongfigParam[LoopIndex].PortName;
		GPIO_Init(&BtnParam);
		BtnState[LoopIndex]= BTN_OFF;
		
	}
}
BTN_StateType BTN_GetState(uint8_t BtnId)
{
	uint8_t PinData;
	GPIO_Read_Param_t BtnParam;
	unsigned char ActiveType = BTN_CongfigParam[BtnId].ConnetionType << BTN_CongfigParam[BtnId].PinNumber;
	BtnParam.Mask = 1 << BTN_CongfigParam[BtnId].PinNumber;
	BtnParam.Port_Name = BTN_CongfigParam[BtnId].PortName;
	PinData = GPIO_Read(&BtnParam);
	
	switch(BtnState[BtnId])
	{
		case BTN_OFF:
		{
			
			if(PinData == ActiveType)
			{
				
				BtnState[BtnId] = BTN_JUST_PRESSED;
			}
			else
			{
				BtnState[BtnId] = BTN_OFF;
			}
		}
		break;
		
		case BTN_JUST_PRESSED:
		{
			if(PinData == ActiveType)
			{
				BtnState[BtnId] = BTN_ON;
			}
			else
			{
				BtnState[BtnId] = BTN_JUST_RELEASED;
			}
		}
		break;
		
		case BTN_ON:
		{
			if(PinData == ActiveType)
			{
				BtnState[BtnId] = BTN_ON;
			}
			else
			{
				BtnState[BtnId] = BTN_JUST_RELEASED;
			}
		}
		break;
		
		case BTN_JUST_RELEASED:
		{
			if(PinData == ActiveType)
			{
				BtnState[BtnId] = BTN_JUST_PRESSED;
			}
			else
			{
				BtnState[BtnId] = BTN_OFF;
			}
		}
		break;
	}
	return BtnState[BtnId];
}