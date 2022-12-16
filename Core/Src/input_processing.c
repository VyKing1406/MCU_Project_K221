/*
 * button.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Vuong
 */

#include "input_processing.h"

//buffer save duration of led

int index_1_Nomal = 0;
int index_2_Nomal = 2;
int state_1_Nomal[3] = { 1, 1, 0 };
int state_2_Nomal[3] = { 0, 1, 1 };

void execute_Mode(void) {
	if (MODE == 1) {
		Mode_Nomal();
	}
	if (MODE == 2) {
		Mode_Red();
	}
	if (MODE == 3) {
		Mode_Yellow();
	}
	if (MODE == 4) {
		Mode_Green();
	}

}

void Button_listens() {
	if (flag_button_press[0]) {
		Mode_Button();
	}
	if (flag_button_press[1]) {
		Add_Button();
	}
	if (flag_button_press[2]) {
		Confirm_Button();
	}
	if(flag_button_press[3])
	{
		Perdes_Button();
	}
	return;
}

void Mode_Button() {
	if (MODE++ == 5) {
		MODE = 1;
	}
	if (MODE != 1) {
		Led_buffer_timer[MODE - 2] = Led_timer[MODE - 2];
	}
	flag_button_press[0] = 0;
}

void Add_Button() {
	if (MODE != 1) {
		Led_buffer_timer[MODE - 2]=Led_buffer_timer[MODE - 2]+1000;
		flag_button_press[1] = 0;
	}
	return;
}

void Confirm_Button() {
	if (MODE != 1) {
		Led_buffer_timer[MODE - 2] = Led_timer[MODE - 2];
		flag_button_press[2] = 0;
	}
	return;
}


void Perdes_Button(){
	/// Gọi hàm Lợi.
	pedestrianFlag = 1;
	pedestrian_fsm();
	flag_button_press[3] = 0;
}

void Mode_Nomal() //*
{
	if (Led_buffer_1_timer[index_1_Nomal] == 0) {
		if (index_1_Nomal++ == 3) {
			index_1_Nomal = 0;
		}

		Led_buffer_1_timer[index_1_Nomal] = Led_timer[index_1_Nomal];

		Led_display(Led_11_Pin, Led_12_Pin, state_1_Nomal[index_1_Nomal],
				state_2_Nomal[index_1_Nomal], GPIOA, GPIOB);

		return;
	}
	if (Led_buffer_2_timer[index_2_Nomal] == 0) {
		if (index_2_Nomal-- == -1) {
			index_2_Nomal = 2;
		}
		Led_buffer_2_timer[index_2_Nomal] = Led_timer[index_1_Nomal];
		Led_display(Led_21_Pin, Led_22_Pin, state_1_Nomal[index_2_Nomal],
				state_2_Nomal[index_2_Nomal], GPIOB, GPIOB);
		return;
	}
	Led_buffer_1_timer[index_1_Nomal]--;
	Led_buffer_2_timer[index_2_Nomal]--;
	return;
}

void Mode_Red() {
	Led_display(Led_11_Pin, Led_12_Pin, 0, 1, GPIOA, GPIOB);
	Led_display(Led_21_Pin, Led_22_Pin, 0, 1, GPIOB, GPIOB);
	return;
}

void Mode_Yellow() {
	Led_display(Led_11_Pin, Led_12_Pin, 1, 1, GPIOA, GPIOB);
	Led_display(Led_21_Pin, Led_22_Pin, 1, 1, GPIOB, GPIOB);
	return;
}

void Mode_Green() {
	Led_display(Led_11_Pin, Led_12_Pin, 1, 0, GPIOA, GPIOB);
	Led_display(Led_21_Pin, Led_22_Pin, 1, 0, GPIOB, GPIOB);
	return;
}









