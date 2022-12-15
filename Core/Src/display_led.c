/*
 * display_led.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Vuong
 */

#include "display_led.h"

void Led_display(uint16_t LOW, uint16_t HIGHT, int state_1, int state_2,
		GPIO_TypeDef *GPIO_1, GPIO_TypeDef *GPIO_2) {
	HAL_GPIO_WritePin(GPIO_1, LOW, state_1);
	HAL_GPIO_WritePin(GPIO_2, HIGHT, state_2);
}

void Terminal_display() {
	return;
}
