#ifndef INC_MOTOR_CTL_H_
#define INC_MOTOR_CTL_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include <main.h>

 ////////////////////Setting PWM to send speed_set////////////////
void MX_TIM1_Init(void);
void MX_TIM8_Init(void);

void PWM_Init(void);
void st_motor1(int speed);
void st_motor2(int speed);
void st_motor3(int speed);
void st_motor4(int speed);

void chay_thang(int speed);

void chay_lui(int speed);

void chay_phai(int speed);

void chay_trai(int speed);

void xoay_phai(int speed);

void xoay_trai(int speed);

int speed_shift(int speed);

void tha_long(void);

void stop(void);
#ifdef __cplusplus
}
#endif
#endif /* INC_MOTOR_CTL_H_ */
