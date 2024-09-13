#include "KEYPAD.h"
char KEYMAP[NUMROWS][NUMCOLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
KEYPAD_Name KeyPad;
char key;

static void KEYPAD_Delay(uint16_t Time)
{
	HAL_Delay(Time);
}
void KEYPAD4X4_Init(KEYPAD_Name* KEYPAD, char KEYMAP[NUMROWS][NUMCOLS],
										GPIO_TypeDef* COL1_PORT, uint32_t COL1_PIN,
										GPIO_TypeDef* COL2_PORT, uint32_t COL2_PIN,
										GPIO_TypeDef* COL3_PORT, uint32_t COL3_PIN,
										GPIO_TypeDef* COL4_PORT, uint32_t COL4_PIN,
										GPIO_TypeDef* ROW1_PORT, uint32_t ROW1_PIN,
										GPIO_TypeDef* ROW2_PORT, uint32_t ROW2_PIN,
										GPIO_TypeDef* ROW3_PORT, uint32_t ROW3_PIN,
										GPIO_TypeDef* ROW4_PORT, uint32_t ROW4_PIN)
{
	KEYPAD->ColPort[0] = COL1_PORT; //Copy gia tri vao keypad
	KEYPAD->ColPort[1] = COL2_PORT;
	KEYPAD->ColPort[2] = COL3_PORT;
	KEYPAD->ColPort[3] = COL4_PORT;
	KEYPAD->ColPins[0] = COL1_PIN;
	KEYPAD->ColPins[1] = COL2_PIN;
	KEYPAD->ColPins[2] = COL3_PIN;
	KEYPAD->ColPins[3] = COL4_PIN;

	KEYPAD->RowPort[0] = ROW1_PORT;
	KEYPAD->RowPort[1] = ROW2_PORT;
	KEYPAD->RowPort[2] = ROW3_PORT;
	KEYPAD->RowPort[3] = ROW4_PORT;
	KEYPAD->RowPins[0] = ROW1_PIN;
	KEYPAD->RowPins[1] = ROW2_PIN;
	KEYPAD->RowPins[2] = ROW3_PIN;
	KEYPAD->RowPins[3] = ROW4_PIN;

	for(int colum = 0; colum < NUMCOLS; colum++)
	{
		for(int row = 0; row < NUMROWS; row++)
		{
			KEYPAD->MAP[row][colum] = KEYMAP[row][colum];
		}
	}

	HAL_GPIO_WritePin(KEYPAD->ColPort[0],KEYPAD->ColPins[0],GPIO_PIN_SET);
	HAL_GPIO_WritePin(KEYPAD->ColPort[1],KEYPAD->ColPins[1],GPIO_PIN_SET);
	HAL_GPIO_WritePin(KEYPAD->ColPort[2],KEYPAD->ColPins[2],GPIO_PIN_SET);
	HAL_GPIO_WritePin(KEYPAD->ColPort[3],KEYPAD->ColPins[3],GPIO_PIN_SET);
}
char KEYPAD4X4_Readkey(KEYPAD_Name* KEYPAD) // Scan Colums
{
	KEYPAD->Value = 0;
	for(int colum = 0; colum < NUMCOLS; colum++)
	{
		HAL_GPIO_WritePin(KEYPAD->ColPort[colum],KEYPAD->ColPins[colum],GPIO_PIN_RESET);
		for(int row = 0; row < NUMROWS; row++)
		{
			if(HAL_GPIO_ReadPin(KEYPAD->RowPort[row],KEYPAD->RowPins[row]) == 0)
			{
				KEYPAD_Delay(50);// debound
				while(HAL_GPIO_ReadPin(KEYPAD->RowPort[row],KEYPAD->RowPins[row])==0){}
				KEYPAD->Value = KEYPAD->MAP[row][colum];

				return KEYPAD->Value;
			}
		}
		HAL_GPIO_WritePin(KEYPAD->ColPort[colum],KEYPAD->ColPins[colum],GPIO_PIN_SET);
	}

	return 0;
}
void GPIO_KeyPad_Init(void)
{	//
	GPIO_InitTypeDef gpio;
	//Khoi tao cac chan Col Ouput,
	 gpio.Pin = GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_1;
	  gpio.Mode = GPIO_MODE_OUTPUT_PP;
	  gpio.Pull = GPIO_NOPULL;
	  gpio.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOC, &gpio);
	  //khoi tao cac chan hang Input_pull up
	  gpio.Pin = GPIO_PIN_15|GPIO_PIN_14|GPIO_PIN_13;
	 	  gpio.Mode = GPIO_MODE_INPUT;
	 	  gpio.Pull = GPIO_PULLUP;
	 	  gpio.Speed = GPIO_SPEED_FREQ_LOW;
	 	  HAL_GPIO_Init(GPIOC, &gpio);

	 	 gpio.Pin = GPIO_PIN_6;
	 		  gpio.Mode = GPIO_MODE_INPUT;
	 		  gpio.Pull = GPIO_PULLUP;
	 		  gpio.Speed = GPIO_SPEED_FREQ_LOW;
	 		  HAL_GPIO_Init(GPIOE, &gpio);

}
void KeyPad_Init(void)
{
	GPIO_KeyPad_Init();
	KEYPAD4X4_Init(&KeyPad, KEYMAP, GPIOC,GPIO_PIN_0,GPIOC,GPIO_PIN_2,GPIOC,GPIO_PIN_3,GPIOC,GPIO_PIN_1,GPIOC,GPIO_PIN_15,GPIOC,GPIO_PIN_14,GPIOC,GPIO_PIN_13,GPIOE,GPIO_PIN_6);

}
void KEYPAD4x4_Config(KEYPAD_Name* KEYPAD, char KEYMAP_Config[NUMROWS][NUMCOLS])
{
	for(int colum = 0; colum < NUMCOLS; colum++)
	{
		for(int row = 0; row < NUMROWS; row++)
		{
			KEYPAD->MAP[row][colum] = KEYMAP_Config[row][colum];
		}
	}
}
