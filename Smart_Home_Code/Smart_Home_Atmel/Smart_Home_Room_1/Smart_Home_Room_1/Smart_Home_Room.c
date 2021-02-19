/*
 * Smart_Home_Room.c
 *
 * Created: 2/18/2021 5:28:13 PM
 *  Author: Osama Moussa
 */ 

#include "Smart_Home_Room.h"

void Smart_Home_Room_Init(void)
{
   Delay_Init();
   SPI_Slave_Init();
   Led_Init();
   LCD_Init();
   DC_Motor_Init();	
   Servo_Motor_Init();
   Temp_Sensor_Init();
}
