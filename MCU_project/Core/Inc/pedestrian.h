/*
 * pedestrian.h
 *
 *  Created on: Dec 15, 2022
 *      Author: loing
 */

#ifndef INC_PEDESTRIAN_H_
#define INC_PEDESTRIAN_H_

#include "main.h"

extern int timeLeft;
extern int currentTrafficLight;
extern int timePWM;
extern int timeFSM;

void pedestrian_fsm();


#endif /* INC_PEDESTRIAN_H_ */
