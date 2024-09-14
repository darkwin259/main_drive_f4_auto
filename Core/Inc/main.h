
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f4xx_hal.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
UART_HandleTypeDef huart1;
ADC_HandleTypeDef hadc1;

CAN_HandleTypeDef hcan1;

I2C_HandleTypeDef hi2c1;


TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4,htim14;
TIM_HandleTypeDef htim5;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;


void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);
void Error_Handler(void);

#include "motor_ctl.h"
#define Basic_speed		100
#define Fast_speed		240 //55
uint8_t RUN_ABLE;

#include "line.h"

volatile int MotorSpeed[5] ;
volatile uint8_t led[8];
volatile uint8_t led2[8];
volatile int goc,goc0;
int so_ngatu;
uint32_t time1;
uint32_t lastHit;
char data[60];
int values[25];
uint8_t flag;
uint8_t rcv_buffer,count;
#define Kp				5
#define Ki				0
#define Kd				25
volatile int P_1,I_1,D_1,PID_1,lech_1,pre_lech_1;

#define KP				0
#define KI				0
#define KD				0
int P_2,I_2,D_2,PID_2,lech_2,pre_lech_2;


#define Kp_a			5
#define Ki_a			0
#define Kd_a			7
int P_a,I_a,D_a,PID_a,lech_ag,pre_lech_ag;


//delay
#include "delay.h"
uint32_t time_run;
float time;


//ps4
#include "ps4.h"



//keypad_lcd
#include "keypad_lcd.h"

char button[4];


//ban bong
#include "banbong.h"
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
