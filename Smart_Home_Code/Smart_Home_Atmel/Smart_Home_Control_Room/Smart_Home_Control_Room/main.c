/*
* Smart_Home_Control_Room.c
*
* Created: 2/18/2021 7:23:20 AM
* Author : Osama Moussa
*/

#include "Smart_Home_Control_Room.h"

int main(void)
{
	Smart_Home_Control_Room_Init();
	Smart_Home_Cmd_Type Cmd_From_Device;
	while (1)
	{
	    Cmd_From_Device = (Uint8)Blutooth_Receive_From_Device_Char();
		Smart_Home_Control_Room_Send_Cmd(Cmd_From_Device);
		
		switch(Cmd_From_Device)
		{
			case Smart_Home_Toggle_Light_Cmd:
			LCD_Clear();
			LCD_Write_String("Room1 Toggle");
			LCD_Write_String_xy("Light",LCD_Line_2, LCD_Position_1);
			break;
			
			case Smart_Home_Measure_Temp_Cmd:
			LCD_Clear();
			LCD_Write_String("Room1 Measure ");
			LCD_Write_String_xy("Temperature",LCD_Line_2, LCD_Position_1);
			break;
			
			case Smart_Home_SpeedUP_Motor_Cmd:
			LCD_Clear();
			LCD_Write_String("Room1 Fan Speed");
			LCD_Write_String_xy("Up",LCD_Line_2, LCD_Position_1);
			break;
			
			case Smart_Home_SpeedDown_Motor_Cmd:
			LCD_Clear();
			LCD_Write_String("Room1 Fan Speed");
			LCD_Write_String_xy("Down",LCD_Line_2, LCD_Position_1);
			break;
			
			case Smart_Home_Stop_Motor_Cmd:
			LCD_Clear();
			LCD_Write_String("Room1 Stop Fan");
			break;
			
			case Smart_Home_Close_Door_Cmd:
			LCD_Clear();
			LCD_Write_String("Room1 Close Door");
			break;
			
			case Smart_Home_Open_Door_Cmd:
			LCD_Clear();
			LCD_Write_String("Room1 Open Door");
			break;
		}
	}
}

