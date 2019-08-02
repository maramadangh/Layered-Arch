/*
 * AVR_Layered_Architecture.c
 *
 * Created: 9/3/2016 8:55:52 AM
 * Author : Master
 */ 

#include <avr/io.h>
#include "ECU_LED.h"
#include "ECU_BTN.h"

uint8_t Check_Btn(void);
void Update_Value(uint8_t value);

int main(void)
{
    /* Replace with your application code */
	uint8_t activeBtnId=0;
	uint8_t value=0;

	LED_Init();
	BTN_Init();
	
    while (1) 
    {
		activeBtnId = Check_Btn();
		switch(activeBtnId)
		{
			case 0:
				if (value<7)
				{
					value++;
				}
			break;
			case 1:
				if (value>0)
				{
					value--;
				}
			break;
			case 2:
				
				value=0;
				
			break;
			default:
			break;
		}
		Update_Value(value);
    }
}

uint8_t Check_Btn(void)
{
	BTN_StateType btnState = BTN_OFF;
	uint8_t activeBtnId = 255;
	uint8_t index;
	for (index=0;index<3;index++)
	{
		btnState = BTN_GetState(index);
		if (btnState == BTN_JUST_RELEASED)
		{
			activeBtnId = index;
			
			index = 3;
		}
	}
	return activeBtnId;
}
void Update_Value(uint8_t value)
{
	uint8_t index;
	for (index=0;index<3;index++)
	{
		//LED_SetData(index,(LED_DataType)((value&(1U<<index))>> index));
		LED_SetData(index,(LED_DataType)value % 2);
		value = value / 2;
	}
}