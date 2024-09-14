
#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void MX_TIM4_Init(void);

uint32_t millies(void);



#define SYSTICK_LOAD (SystemCoreClock/1000000U)
#define SYSTICK_DELAY_CALIB (SYSTICK_LOAD >> 1)

void delay_us(uint16_t us);
void delay_ms(uint16_t ms);
void MX_TIM14_Init(void);












#ifdef __cplusplus
}
#endif
#endif /* INC_DELAY_H_ */
