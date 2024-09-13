#ifndef __KEYPAD_H
#define __KEYPAD_H
#include "stm32f4xx_hal.h"
#define NUMROWS 4
#define NUMCOLS 4

typedef struct
{
	uint32_t RowPins[NUMROWS];
	uint32_t ColPins[NUMCOLS];
	GPIO_TypeDef* RowPort[NUMROWS];
	GPIO_TypeDef* ColPort[NUMCOLS];
	char MAP[NUMROWS][NUMCOLS];
	char Value;
}KEYPAD_Name;

void KEYPAD4X4_Init(KEYPAD_Name* KEYPAD, char KEYMAP[NUMROWS][NUMCOLS],
										GPIO_TypeDef* COL1_PORT, uint32_t COL1_PIN,
										GPIO_TypeDef* COL2_PORT, uint32_t COL2_PIN,
										GPIO_TypeDef* COL3_PORT, uint32_t COL3_PIN,
										GPIO_TypeDef* COL4_PORT, uint32_t COL4_PIN,
										GPIO_TypeDef* ROW1_PORT, uint32_t ROW1_PIN,
										GPIO_TypeDef* ROW2_PORT, uint32_t ROW2_PIN,
										GPIO_TypeDef* ROW3_PORT, uint32_t ROW3_PIN,
										GPIO_TypeDef* ROW4_PORT, uint32_t ROW4_PIN);
char KEYPAD4X4_Readkey(KEYPAD_Name* KEYPAD);
void KeyPad_Init(void);
void GPIO_KeyPad_Init(void);
#endif
