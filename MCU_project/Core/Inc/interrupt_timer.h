/*
 * timer_interrupt.h
 *
 *  Created on: Oct 11, 2022
 *      Author: Vuong
 */
#ifndef INC_INTERRUPT_TIMER_H_
#define INC_INTERRUPT_TIMER_H_

//////////////////////////////////////////////////////////
#define TIMER_CYCLE 10
#define NU_OF_TIMER 7

////////////////////////////////////////////////////////


extern int timer_flag[NU_OF_TIMER];
extern int timer_counter[NU_OF_TIMER];
void setTimer ( int index, int duration );


void timer_run();


extern int timer0_flag;

void set_Timer0 ( int duration );
void timer_ped_run();
void set_timer_ped(int duration);

#endif /* INC_INTERRUPT_TIMER_H_ */
