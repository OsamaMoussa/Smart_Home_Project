/*
 * Smart_Home_Room.h
 *
 * Created: 2/18/2021 5:27:49 PM
 *  Author: Osama Moussa
 */ 


#ifndef SMART_HOME_ROOM_H_
#define SMART_HOME_ROOM_H_

#include "STD_Types.h"
#include "Delay.h"
#include "Led.h"
#include "LCD.h"
#include "SPI_Slave.h"
#include "DC_Motor.h"
#include "Servo_Motor.h"
#include "Temp_Sensor.h"

#define Smart_Home_SPI_Check_Byte 0x55

typedef enum{
	Smart_Home_Toggle_Light_Cmd    ='0',
	Smart_Home_Measure_Temp_Cmd    ='1',
	Smart_Home_SpeedUP_Motor_Cmd   ='2',
	Smart_Home_SpeedDown_Motor_Cmd ='3',
	Smart_Home_Stop_Motor_Cmd      ='4',
	Smart_Home_Close_Door_Cmd      ='5',
	Smart_Home_Open_Door_Cmd       ='6'
    }Smart_Home_Cmd_Type;

void Smart_Home_Room_Init(void);

#endif /* SMART_HOME_ROOM_H_ */