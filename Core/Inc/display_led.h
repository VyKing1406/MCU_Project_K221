/*
 * display_led.h
 *
 *  Created on: Dec 15, 2022
 *      Author: Vuong
 */

#ifndef INC_DISPLAY_LED_H_
#define INC_DISPLAY_LED_H_

#include "main.h"

void Led_display(uint16_t LOW, uint16_t HIGHT, int state_1, int state_2,
		GPIO_TypeDef *GPIO_1, GPIO_TypeDef *GPIO_2);
void Terminal_display();

#endif /* INC_DISPLAY_LED_H_ */
