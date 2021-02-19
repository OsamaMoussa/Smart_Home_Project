/*
* Smart_Home_Control_Room.c
*
* Created: 2/18/2021 5:36:52 PM
*  Author: Osama Moussa
*/
#include "Smart_Home_Control_Room.h"

void Smart_Home_Control_Room_Init()
{
	Delay_Init();
	SPI_Master_Init();
	Bluetooth_Init();
	LCD_Init();
}

void Smart_Home_Control_Room_Send_Cmd(Smart_Home_Cmd_Type Cmd_From_Device)
{
	if (Cmd_From_Device == Smart_Home_Toggle_Light_Cmd|
	Cmd_From_Device == Smart_Home_Measure_Temp_Cmd|
	Cmd_From_Device == Smart_Home_SpeedUP_Motor_Cmd|
	Cmd_From_Device == Smart_Home_SpeedDown_Motor_Cmd|
	Cmd_From_Device ==Smart_Home_Stop_Motor_Cmd|
	Cmd_From_Device == Smart_Home_Close_Door_Cmd|
	Cmd_From_Device == Smart_Home_Open_Door_Cmd)
	{
		SPI_Master_Send_Data(Smart_Home_Room_1,Cmd_From_Device);
	}
	else
	{
		return;
	}
	
}


