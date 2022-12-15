/*
 * pedestrian.c
 *
 *  Created on: Dec 15, 2022
 *      Author: loing
 */


#include "pedestrian.h"

int timeLeft = 0;
int currentTrafficLight;
int timeFSM = 0;
int timePWM = 0;

void pedestrian_fsm(){
	if (pedestrianFlag == 1){
		addTask(pedestrian, 0, 0);
		switch (currentTrafficLight) {
		case GREEN:
			HAL_GPIO_WritePin(GPIOB, PED0_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, PED1_Pin, 0);
			timeFSM=0;
			break;
		case YELLOW:
			HAL_GPIO_WritePin(GPIOB, PED0_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, PED1_Pin, 1);
			break;
		case RED:
			timeFSM++;
			timeLeft = currentTrafficLight;
			if (timeFSM == 500) {
				timeFSM = 0;
				pedestrianFlag = 0;
				timePWM = 0;
			}
			HAL_GPIO_WritePin(GPIOB, PED0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, PED1_Pin, 1);

			if (timeLeft<5) {
				timePWM++;
				if (timePWM>=timeLeft) {
					timePWM = 0;
					__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_3, (5 - timeLeft)*20);
				}
			}
		}
	}
}


