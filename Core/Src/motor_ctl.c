#include "motor_ctl.h"

int speed;
int  RobotSpeed_y=0;
int  RobotSpeed_x=0;

TIM_HandleTypeDef htim1,htim8,htim5;


void MX_TIM1_Init(void)//5kHz
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 71;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 400;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

void MX_TIM8_Init(void)
{

  /* USER CODE BEGIN TIM8_Init 0 */

  /* USER CODE END TIM8_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM8_Init 1 */

  /* USER CODE END TIM8_Init 1 */
  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 15;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 400;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_OC_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_TIMING;
  if (HAL_TIM_OC_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM8_Init 2 */

  /* USER CODE END TIM8_Init 2 */
  HAL_TIM_MspPostInit(&htim8);

}





void PWM_Init(void)
{
	MX_TIM1_Init();
	MX_TIM8_Init();
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_4);

//	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,120);
//	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, 1);
//	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,120);
//	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);
//	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,120);
//	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, 1);
//	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,120);
//	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1);

}

void st_motor1(int speed)
{
	if(speed_shift(speed) > 0){HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 1);}
	else if(speed_shift(speed) <0){HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);}
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,abs(speed_shift(speed))-12);

}

void st_motor2(int speed)
{
	if(speed_shift(speed) > 0){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);}
	else if(speed_shift(speed) <0){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);}
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,abs(speed_shift(speed))-12);

}

void st_motor3(int speed)
{
	if(speed_shift(speed) > 0){HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, 1);}
	else if(speed_shift(speed) <0){HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, 0);}
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,abs(speed_shift(speed))-12);

}

void st_motor4(int speed)
{
	if(speed_shift(speed) > 0){HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 1);}
	else if(speed_shift(speed) <0){HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 0);}
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,abs(speed_shift(speed))-12);

}

//////////**************************************************************////////////////////////

void chay_thang(int speed)
{
	st_motor1(speed);//DC 1
	st_motor2(speed);//DC 2
	st_motor3(-speed);//DC 3
	st_motor4(-speed);//DC 4

}

void chay_lui(int speed)
{
	st_motor1(-speed);//DC 1
	st_motor2(-speed);//DC 2
	st_motor3(speed);//DC 3
	st_motor4(speed);//DC 4
}

void chay_phai(int speed)
{
	st_motor1(8);//DC 1
	st_motor2(speed);//DC 2
	st_motor3(-speed);//DC 3
	st_motor4(8);//DC 4
}

void chay_trai(int speed)
{
	st_motor1(speed);//DC 1
	st_motor2(8);//DC 2
	st_motor3(8);//DC 3
	st_motor4(-speed);//DC 4
}

void xoay_phai(int speed)
{
	st_motor1(speed);//DC 1
	st_motor2(speed);//DC 2
	st_motor3(speed);//DC 3
	st_motor4(speed);//DC 4
}

void xoay_trai(int speed)
{
	st_motor1(-speed);//DC 1
	st_motor2(-speed);//DC 2
	st_motor3(-speed);//DC 3
	st_motor4(-speed);//DC 4
}
void tha_long(void)
{
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,8);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,8);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,8);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,8);
}
void stop(void)
{
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,12);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,12);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,12);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,12);

}
///////////////////////////////////////Loai truong hop khoa cung dong co/////////////////////////////////

int speed_shift(int speed)
{
	if(speed <0){return (speed - 12);}
	if(speed >0){return (speed + 12);}
	else {return (speed + 12);}

}
