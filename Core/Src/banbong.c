#include "banbong.h"

int temp_x,temp_y;
uint8_t temp1 = 100,temp2 = 100;

void TIM3_Init(void)	///50Hz PWM (4 pin: 2 BLDC, !
{


	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_OC_InitTypeDef sConfigOC = {0};


	  htim3.Instance = TIM3;
	  htim3.Init.Prescaler = 719;
	  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim3.Init.Period = 2000;
	  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
		  {
			Error_Handler();
		  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
		  {
			Error_Handler();
		  }
	  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
		  {
			Error_Handler();
		  }
	  if (HAL_TIM_OC_Init(&htim3) != HAL_OK)
		  {
			Error_Handler();
		  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
		  {
			Error_Handler();
		  }
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 0; /// 100 200(min max)
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
		  {
			Error_Handler();
		  }
	  if (HAL_TIM_OC_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
		  {
			Error_Handler();
		  }
	  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
		  {
			Error_Handler();
		  }
	  if (HAL_TIM_OC_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
		  {
			Error_Handler();
		  }

	  HAL_TIM_MspPostInit(&htim3);

	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

void TIM2_Init(void)	///dong co goc tam
{


  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};


  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 71;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 100;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	  {
		Error_Handler();
	  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	  {
		Error_Handler();
	  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	  {
		Error_Handler();
	  }
  if (HAL_TIM_OC_Init(&htim2) != HAL_OK)
	  {
		Error_Handler();
	  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	  {
		Error_Handler();
	  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	  {
		Error_Handler();
	  }
  if (HAL_TIM_OC_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	  {
		Error_Handler();
	  }
//  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
//	  {
//		Error_Handler();
//	  }
//  if (HAL_TIM_OC_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
//	  {
//		Error_Handler();
//	  }

  HAL_TIM_MspPostInit(&htim2);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
}
void angle_adjust(void)
{
	/*goc tam*/
	if(values[13]  && temp_y > 65)
	{
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,90);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);

	}else if (values[13]  && temp_y < -65)
	{
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,90);
	}  else
	{
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
	}
	/*khoi dong 2 bldc*/
		if(values[4])
		{
			if(temp1 >= 100 && temp1 <= 160)
				{
					__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,temp1);

					temp1 = temp1 + 5;
					if (temp1 > 160)
					{
						temp1 = 160;
						__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,temp1);
					}
				}
		}else
		{
			temp1 = 100;
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,temp1);
		}
		/*chan cua tim4 kich hoat role ban bong*/
	if(values[10])
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, 1);
		}else {HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, 0);}

	//	if(values[13] && temp_y > 0 )
	//	{
	//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,temp1);
	//	}
	//	if(values[13] && temp_y < 0 )
	//	{
	//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,temp1);
	//	}
	//	if(values[13] && abs(temp_y) > 100)
	//	{
	//		if(temp1 >= 100 && temp1 <= 200)
	//		{
	//			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,temp1);
	//
	//			temp1 = temp1 + sign(temp_x);
	//
	//			if (temp1 > 200) temp1 = 200;
	//
	//			else if ( temp1 < 100) temp1 = 100;
	//		}
	//	}
}
void phat_vo(uint8_t mode)
{
	if(mode)
	{

	}else {}
}
