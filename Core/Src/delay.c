#include "delay.h"

extern TIM_HandleTypeDef htim4,htim14;
extern uint32_t time_run;
void MX_TIM4_Init(void)
{


//50ms
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 719;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 5000;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim4);
  HAL_TIM_Base_Start_IT(&htim4);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM4)
	{
		time_run++;
		RUN_ABLE = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5);
	}
}

uint32_t millies(void)//0.05; 1s ung voi 20 lan dem; millies tra ve 400 ung voi 1s thoi gian thuc, va 1600 ung voi 4s
{
	return time_run*20;
}

void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim14,0);

//	uint16_t temp = __HAL_TIM_GET_COUNTER(&htim14);
	while(__HAL_TIM_GET_COUNTER(&htim14) < us);

}
void delay_ms(uint16_t ms)
{
    do {
        for (uint32_t i = 0; i < ms; i++) {
            delay_us(1000);
        }
    } while (0);
}

void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 71;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 65535;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */
  HAL_TIM_Base_Start(&htim14);
  /* USER CODE END TIM14_Init 2 */

}
