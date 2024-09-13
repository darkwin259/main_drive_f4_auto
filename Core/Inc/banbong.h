#ifndef INC_BANBONG_H_
#define INC_BANBONG_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "ps4.h"



extern TIM_HandleTypeDef htim3;
void TIM3_Init(void);
void angle_adjust(void);

#ifdef __cplusplus
}
#endif
#endif /* INC_BANBONG_H_ */
