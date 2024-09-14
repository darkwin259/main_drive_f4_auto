#ifndef INC_PS4_H_
#define INC_PS4_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

extern UART_HandleTypeDef huart1;


void MX_USART1_UART_Init(void);

void split_array(void);

void Control_Move(void);

void Hand_Control(void);

int  sign(int number);








#ifdef __cplusplus
}
#endif
#endif /* INC_PS4_H_ */
