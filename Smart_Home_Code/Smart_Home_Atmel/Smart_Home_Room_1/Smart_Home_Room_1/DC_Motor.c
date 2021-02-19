/*
* DC_Motor.c
*
* Created: 2/14/2021 5:35:15 PM
*  Author: Osama Moussa
*/
#include "DC_Motor.h"

void DC_Motor_Init(void)
{
	DIO_Channel_Mode(DC_Motor_IN1,Output);
	DIO_Channel_Mode(DC_Motor_IN2,Output);
	DIO_Channel_Mode(DC_Motor_E,Output);
	Timer1_Init_Type Timer1_DC_Motor_Init = {Timer1_WG_FastPWM_8Bit_Mode, DC_Motor_COM, Timer1_COM_Clear_Mode, Timer1_CS_64Presc};
	Timer1_Init(&Timer1_DC_Motor_Init);
}

void DC_Motor_CW(DC_Motor_Speed_type Speed)
{
	DIO_Channel_Write(DC_Motor_IN2,STD_Low);
	DIO_Channel_Write(DC_Motor_IN1,STD_High);
	Timer1_NonInv_FPWM_Duty(DC_Motor_COM , Speed);
}

void DC_Motor_ACW(DC_Motor_Speed_type Speed)
{

	DIO_Channel_Write(DC_Motor_IN2,STD_High);
	DIO_Channel_Write(DC_Motor_IN1,STD_Low);
	Timer1_NonInv_FPWM_Duty(DC_Motor_COM , Speed);
}

void DC_Motor_Stop(void)
{
	DIO_Channel_Write(DC_Motor_IN2,STD_High);
	DIO_Channel_Write(DC_Motor_IN1,STD_High);
}
