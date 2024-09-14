#include "keypad_lcd.h"


void key_pad_gpio(void)
{
	GPIO_InitTypeDef key_pad = {0};

	key_pad.Mode	=	GPIO_MODE_INPUT;
	key_pad.Speed	=	GPIO_SPEED_FAST;
	key_pad.Pull	=	GPIO_PULLUP;
	key_pad.Pin		=	GPIO_PIN_3 | GPIO_PIN_1 | GPIO_PIN_15 | GPIO_PIN_13;
	HAL_GPIO_Init(GPIOC, &key_pad);

	key_pad.Mode	=	GPIO_MODE_OUTPUT_OD;
	key_pad.Speed	=	GPIO_SPEED_FAST;
	key_pad.Pin		=	GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_14 | GPIO_PIN_6;
	HAL_GPIO_Init(GPIOC, &key_pad);

}

char read_1(void)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0,  0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2,  0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6,  1);

	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3));
			return 'K';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1));
			return '1';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15));
			return '4';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13));
			return '7';
	}
	return '0';
}

char read_2(void)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0,  0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2,  0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6,  0);

	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3));
			return 'A';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1));
			return '2';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15));
			return '5';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13));
			return '8';
	}
	return '0';
}

char read_3(void)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0,  0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2,  1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6,  0);

	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3));
			return '.';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1));
			return '3';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15));
			return '6';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13));
			return '9';
	}
	return '0';
}

char read_4(void)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0,  1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2,  0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6,  0);

	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3));
			return 'E';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1));
			return 'B';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15));
			return '+';
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) != 0)
	{
		while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13));
			return '-';
	}
	return '0';
}

char read_keypad()
{
	static uint16_t lastpress=0;

	if( millis()- lastpress>100){
	button[1]	= 	read_1();
	button[2]	=	read_2();
	button[3]	=	read_3();
	button[4]	=	read_4();
	if(	button[1] != '0' ) {/*delay_ms(10) */ lastpress= millis();  lcd_Data_Write(	button[1]); return  button[1]; }
	if(	button[2] != '0' ) {/*delay_ms(10) */ lastpress= millis();  lcd_Data_Write(	button[2]); return  button[2]; }
	if(	button[3] != '0' ) {/*delay_ms(10) */ lastpress= millis();  lcd_Data_Write( button[3]); return  button[3]; }
	if(	button[4] != '0' ) {/*delay_ms(10) */ lastpress= millis();  lcd_Data_Write(	button[4]); return  button[4]; }
}
return '0';

}
