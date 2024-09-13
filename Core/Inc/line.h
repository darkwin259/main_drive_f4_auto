

#ifndef INC_LINE_H_
#define INC_LINE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"


extern volatile uint8_t led[8];
extern volatile uint8_t led2[8];
extern int so_ngatu;
extern uint32_t time1;
extern uint32_t lastHit;

extern TIM_HandleTypeDef htim5;

extern UART_HandleTypeDef huart1;
extern volatile int goc,goc0;

extern char data[60];
extern int values[25];
extern uint8_t flag;
extern volatile int P_1,I_1,D_1,PID_1,lech_1,pre_lech_1;
//
//#define Kp				0
//#define Ki				0
//#define Kd				0
extern int P_2,I_2,D_2,PID_2,lech_2,pre_lech_2;

//#define KP				0
//#define KI				0
//#define KD				0

extern int P_a,I_a,D_a,PID_a,lech_ag,pre_lech_ag;

//#define Kp_a			0
//#define Ki_a			0
//#define Kd_a			0

void TIM5_Init(void);

void MX_USART1_UART_Init(void);

void split_array(void);

void Line_PIN_Config(void);

void lech_value_1(void);

void lech_value_2(void);

void goc_lech_value(void);

void nga4_count(void);

void pid_lech_1(void);

void pid_lech_2(void);

void pid_lech_1(void);

void pid_lech_2(void);

void pid_goc(void);

/********************************************************PID_VALUE_TO_MOTOR****************************************************/
void motor_foward_pid(int speed);
void motor_backward_pid(int speed);
void motor_rightside_pid(int speed);
void motor_leftside_pid(int speed);

/**********************************-Line Follow-**************************************/
void linefollow_foward(int speed);
void linefollow_backward(int speed);
void linefollow_rightside(int speed);
void linefollow_leftside(int speed);

void linefollow_foward_time(int speed, uint16_t time);
void linefollow_backward_time(int speed, uint16_t time);
void linefollow_leftside_time(int speed, uint16_t time);
void linefollow_rightside_time(int speed, uint16_t time);

void run_angle(uint16_t v_robot, uint16_t angle);
void run_angle_time(uint16_t v_robot,uint16_t angle,uint16_t time);

/***********************-Run with encoder-*************************/

void run_foward_steps(int speed, uint16_t step);
void run_backward_steps(uint16_t speed, uint16_t step);
void run_right_steps(uint16_t speed, uint16_t step);
void run_left_steps(uint16_t speed, uint16_t step);
#ifdef __cplusplus
}
#endif
#endif /* INC_LINE_H_ */
