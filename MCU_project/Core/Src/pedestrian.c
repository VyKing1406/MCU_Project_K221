/*
 * pedestrian.c
 *
 *  Created on: Dec 15, 2022
 *      Author: loing
 */


#include "pedestrian.h"

int timeLeft = 0;
int currentLight;
void pedestrian_display_led() {
	switch (currentLigh) {
	case GREEN:
		HAL_GPIO_WritePin(PED0_GPIO_Port, PED0_Pin, 0);
		HAL_GPIO_WritePin(PED1_GPIO_Port, PED1_Pin, 0);
		break;
	case RED:
		HAL_GPIO_WritePin(PED0_GPIO_Port, PED0_Pin, 0);
		HAL_GPIO_WritePin(PED1_GPIO_Port, PED1_Pin, 0);
		pedestrian_buzzer();

		addTask(5000,xoa, 0);
		if ()
		break;
	}
}


void xoa{
	deletaTask();
}

void pedestrian_buzzer(){
	int i = 0;
	while ()
}
