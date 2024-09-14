#include "ps4.h"
#include "motor_ctl.h"

extern int RobotSpeed_y,RobotSpeed_x;


uint16_t sspeed;


//void MX_USART1_UART_Init(void)
//{
//
//
//  huart1.Instance = USART1;
//  huart1.Init.BaudRate = 19200;
//  huart1.Init.WordLength = UART_WORDLENGTH_8B;
//  huart1.Init.StopBits = UART_STOPBITS_1;
//  huart1.Init.Parity = UART_PARITY_NONE;
//  huart1.Init.Mode = UART_MODE_TX_RX;
//  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
//  if (HAL_UART_Init(&huart1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART1_Init 2 */
//
//  /* USER CODE END USART1_Init 2 */
//
//}
//
//void split_array(void)
//{
//
//
//
//     // Mảng để lưu các giá trị
//    char *token;
//    char delim[] = ","; // Ký tự phân tách giữa các giá trị
//    int i = 0;
//
//    // Sử dụng strtok để tách chuỗi
//    token = strtok(data, delim);
//
//    // Duyệt qua các phần tử đã được tách
//    while (token != NULL) {
//        sscanf(token, "%d", &values[i]); // Chuyển đổi chuỗi thành số nguyên và lưu vào mảng
//        i++;
//        token = strtok(NULL, delim); // Tiếp tục tách chuỗi
//    }
//
//}




void Control_Move(void)
{
	int tempy,tempx,xoay;
	xoay =	values[2];
	tempy = values[1];
	tempx = values[0];
	//gioi han gia tri
	if(abs(tempx) < 50)
	{
		tempx = 0;
	}
//	else if(abs(tempx) > 127 )
//	{
//		tempx = 127 * sign(tempx);
//	}
	if(abs(tempy) < 50)
	{
		tempy = 0;
	}
//	else if(abs(tempy) > 127 )
//	{
//		tempy = 127 * sign(tempy);
//	}
	if(abs(xoay) < 50)
	{
		xoay = 0;
	}
//	else if(abs(xoay) > 127 )
//	{
//		xoay = 127 * sign(xoay);
//	}


	if(abs(tempx) > abs(tempy))
	{
		tempy = 0;
	}
	else if(abs(tempx) < abs(tempy))
	{
		tempx = 0;
	}


		if(  (values[12] == 1  ||  values[14] == 1)   &&  (abs(tempy)>0 || abs(tempx)>0 || abs(xoay)> 0) )
		{// neu EABLE
			if( values[12]  && abs(tempy)>0)
				{
					sspeed = Basic_speed;
					RobotSpeed_y = sspeed * sign(tempy);
					chay_thang(	RobotSpeed_y);
				}else if( values[14]  &&  abs(tempy)>0)
				{
					sspeed=Fast_speed;
					RobotSpeed_y=  sspeed * sign(tempy);
					chay_thang(	RobotSpeed_y);
				}		else RobotSpeed_y=0;

			if( values[12]  && abs(tempx)>0 )
				{
					sspeed = Basic_speed;
					RobotSpeed_x = sspeed *sign(tempx);
					chay_phai(RobotSpeed_x);
				}else if( values[14]  &&  abs(tempx)>0)
				{
					sspeed = Fast_speed;
					RobotSpeed_x =  sspeed *sign(tempx);;
					chay_phai(RobotSpeed_x);
				}		else RobotSpeed_x = 0;
			//xoay
			 if(   ( values[12] && values[14] ) &&   xoay > 0 )    	xoay_phai(Basic_speed);
			 if(   ( values[12] && values[14] ) &&   xoay < 0 )    	xoay_trai(Basic_speed);


		}else
		{
			tha_long();
			HAL_Delay(10);
			stop();// neu nut 9 and 11  = 0 thi stop het
			RobotSpeed_x=0;
			RobotSpeed_y=0;
		}

		 if(values[16] == 1)
		 {
			 tha_long();
		 }
		tempx=0;
		tempy=0;
		xoay=0;
		flag = 0;
}

void Hand_Control(void)
{
	split_array();
	Control_Move();
	angle_adjust();
	HAL_UART_Receive_IT(&huart1,&rcv_buffer,1);
	HAL_Delay(10);
}


int  sign(int number)
{
	int dau;
	if(number > 0)
	{
		dau = 1;
	}
	else if(number < 0)
	{
		dau = -1;
	}else dau = 0;
	return dau;
}


