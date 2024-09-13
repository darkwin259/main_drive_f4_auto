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

void angle_adjust(void)
{

	temp_x = values[2];
	temp_y = values[3];

	if(/*them 1 dieu kien nut bam khac && */ abs(temp_x) > 100)
	{
		if(temp1 >= 100 && temp1 <= 200)
		{
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,temp1);

			temp1 = temp1 + sign(temp_x);

			if (temp1 > 200) temp1 = 200;

			else if ( temp1 < 100) temp1 = 100;
		}
	}

	if(/*them 1 dieu kien nut bam khac && */abs(temp_y) > 100)
	{
		if(temp2 >= 100 && temp2 < 200 )
		{
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,temp2);

			temp2 = temp2 + sign(temp_y);

			if (temp2 > 200) temp2 = 200;

			else if ( temp2 < 100) temp2 = 100;
		}
	}



}
