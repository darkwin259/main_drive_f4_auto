
#include "main.h"
//speed
//3600 xung/met

//85,150

volatile uint32_t countnn;


void SystemClock_Config(void);
static void MX_GPIO_Init(void);

//static void MX_TIM2_Init(void);
static uint8_t khoi_dong(void);
//static void MX_USART2_UART_Init(void);
//static void MX_USART3_UART_Init(void);

int main(void)
{
	/*system*/
	HAL_Init();
	SystemClock_Config();

	MX_TIM4_Init();
	MX_USART1_UART_Init();
	key_pad_gpio();
	Line_PIN_Config();
	MX_GPIO_Init();
	TIM5_Init();
	TIM3_Init();
	MX_TIM14_Init();
	PWM_Init();
//	khoi_dong();

		memset(&data, 0, sizeof(data));
//		stop();
//		HAL_Delay(2000);
		HAL_UART_Receive_IT(&huart1,&rcv_buffer,1);
////		run_foward_steps(Basic_speed,7200);
////		delay_ms(500);
////		run_backward_steps(Basic_speed,7200);
////		delay_ms(500);
////		run_left_steps(Basic_speed,7200);
////		delay_ms(500);
////		run_right_steps(Basic_speed,7200);
		cho_lenh(1);
		linefollow_foward_time(Basic_speed,1200);
		cho_lenh(2);
		linefollow_backward_time(Basic_speed,1200);
		cho_lenh(8);
		linefollow_leftside_time(Basic_speed,1200);
		cho_lenh(4);
		linefollow_rightside_time(Basic_speed,1200);
		//delay_ms(500);





	while(1)
	{
//		linefollow_foward(Basic_speed);
//		linefollow_rightside(Basic_speed);
//
////		//HAL_Delay(10);
//		pid_goc();
		countnn = __HAL_TIM_GET_COUNTER(&htim5);
		//run_foward_steps(Basic_speed,10000);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,85);
//		HAL_Delay(1000);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,150);
//		HAL_Delay(1000);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,150);
//		HAL_Delay(1000);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,165);
//		HAL_Delay(1000);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,150);
//		HAL_Delay(1000);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,125);
//		HAL_Delay(1000);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,100);
//		HAL_Delay(1000);
		//pid_goc();

	}


	/*****hold till die***********/
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{

		if ((rcv_buffer == 'd') & (flag != 1))// nhan ki tu d ngung nhan
		{
			count = 0;
			flag = 1;
			split_array();
			HAL_UART_Receive_IT(&huart1,&rcv_buffer,1);

		}else if ((rcv_buffer != 'd') & (flag != 1))
		{
			data[count++] = rcv_buffer;
			HAL_UART_Receive_IT(&huart1,&rcv_buffer,1);
			flag = 0;

		}


	}
}


//void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
//{
//	uint16_t count;
//	if(htim->Instance == TIM3)
//	{
//
//	}
//}
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	*/
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/** Initializes the RCC Oscillators according to the specified parameters
	* in the RCC_OscInitTypeDef structure.
	*/
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 144;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 4;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
	Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
							  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
	{
	Error_Handler();
	}
}





static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* khai bao 2 cai den d6 d7
 * khai bao nut nhan	D5 -- bat tat chay
 *  E2   cong tac hanh trinh */



  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();


  /*Configure GPIO pins : PE2 PE3 PE4 PE5
                           PE6 PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PC13 PC14 PC15 PC0
                           PC1 PC2 PC3 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB2 PB12 PB13 PB14
                           PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PE7 PE8 PE9 PE10
                           PE11 PE12 PE13 PE14
                           PE15 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 PD4 PD5
                           PD6 PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PD10 PD11 PD15 PD2
                           PD3 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_15|GPIO_PIN_2
                          |GPIO_PIN_3 | GPIO_PIN_14 |GPIO_PIN_0 | GPIO_PIN_1 ;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PD12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PC10 PC11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

static uint8_t khoi_dong(void)
{
	while(!HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5));
	RUN_ABLE = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_5);
	return RUN_ABLE;
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
