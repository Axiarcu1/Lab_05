/*
 * traffic.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Admin
 */

#include "traffic.h"
#include "timer.h"
#include "button.h"

int status = INIT;

void traffic_light(){	//mode 1 function
	switch(status){
	case INIT:		//initial state
		status = RED_GREEN;
		setTimer1(3000);

		break;
	case RED_GREEN:	//RED1 and GREEN2
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);


		if (timer1_flag == 1 || isButtonPressed(0)){	//counts decreases every second
			status = RED_YELLOW;
			setTimer1(2000);
		}
		break;
	case RED_YELLOW:		//RED1 and YELLOW2
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);

		if (timer1_flag == 1 || isButtonPressed(0)){	//counts decreases every second
			status = GREEN_RED;
			setTimer1(3000);
		}
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);

		if (timer1_flag == 1 || isButtonPressed(0)){	//counts decreases every second
			status = YELLOW_RED;
			setTimer1(2000);
		}
		break;
	case YELLOW_RED:
		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);

		if (timer1_flag == 1 || isButtonPressed(0)){	//counts decreases every second
			status = RED_GREEN;
			setTimer1(3000);
		}
		break;
	default:
		break;
	}
}
