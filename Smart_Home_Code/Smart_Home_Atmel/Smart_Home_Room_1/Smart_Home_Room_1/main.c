/*
* Smart_Home_Room_1.c
*
* Created: 2/18/2021 7:24:09 AM
* Author : Osama Moussa
*/

#include "Smart_Home_Room.h"
#include <stdlib.h>

int main(void)
{
	Smart_Home_Room_Init();
	Smart_Home_Cmd_Type Cmd_From_Control_Room;
	Uint16 Temp_Value = 0;
	Sint8 Temp_Value_String[]={0};
	Uint8 Count=0;		
	while (1)
	{   
		Cmd_From_Control_Room = SPI_Slave_Recieve_Data();
		switch(Cmd_From_Control_Room)
		{
			case Smart_Home_Toggle_Light_Cmd:
			Led_Toggle();
			LCD_Clear();
			Count++;
			if (Count==2)
			{
				LCD_Write_String("Light Turned OFF");
				Count=0;
			}
			else
			{
			     LCD_Write_String("Light Turned ON");	
			}	
			break;
			
			case Smart_Home_Measure_Temp_Cmd:
			Temp_Value=Temp_Sensor_Read_Value();
			itoa(Temp_Value,Temp_Value_String,10);	
			LCD_Clear();
			LCD_Write_String("Temperature: ");
			LCD_Write_String(Temp_Value_String);
			break;
			
			case Smart_Home_SpeedUP_Motor_Cmd:
			DC_Motor_CW(DC_Motor_High_Speed);
			LCD_Clear();
			LCD_Write_String("Fan Speed Up");
			break;
			
			case Smart_Home_SpeedDown_Motor_Cmd:
			DC_Motor_CW(DC_Motor_Low_Speed);
			LCD_Clear();
			LCD_Write_String("Fan Speed Down");
			break;
			
			case Smart_Home_Stop_Motor_Cmd:
			DC_Motor_Stop();
			LCD_Clear();
			LCD_Write_String("Fan Is Stopped");
			break;
			
			case Smart_Home_Close_Door_Cmd:
			Servo_Motor_Angle(0.0);
			LCD_Clear();
			LCD_Write_String("Door Is Closed");
			break;
			
			case Smart_Home_Open_Door_Cmd:
			Servo_Motor_Angle(90.0);
			LCD_Clear();
			LCD_Write_String("Door Is Opened");
			break;
		}
	}
}

